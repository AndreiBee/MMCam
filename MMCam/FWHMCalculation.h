#pragma once
#ifndef FWHMCALCULATION_H
#define FWHMCALCULATION_H

#include <numeric>
#include <thread>
#include <vector>
#include <atomic>
#include <memory>

namespace FWHM
{
	static auto CalculateSumHorizontally
	(
		unsigned short* const dataPtr,
		const int& imageWidth,
		const int& imageHeight,
		unsigned int* const results
	) -> void
	{
		if (!dataPtr || !results) return;
		if (!imageWidth || !imageHeight) return;

		auto calculateSum = []
		(
			const unsigned short* start, 
			const unsigned short* end, 
			int startRow, int rows, 
			unsigned int* results, 
			int imageWidth
			)
			{
				for (auto i = 0; i < rows; ++i)
				{
					const unsigned short* row_start = start + i * imageWidth;
					const unsigned short* row_end = row_start + imageWidth;
					results[startRow + i] = std::accumulate(row_start, row_end, 0u);
				}
			};

		int num_threads = std::max(1u, std::thread::hardware_concurrency());
		int rows_per_thread = imageHeight / num_threads;
		int remaining_rows = imageHeight % num_threads;

		std::vector<std::thread> threads;
		threads.reserve(num_threads);

		for (auto t = 0; t < num_threads; ++t)
		{
			int start_row = t * rows_per_thread;
			int rows_to_process = t < num_threads - 1 ? rows_per_thread : rows_per_thread + remaining_rows;

			const unsigned short* chunk_start = dataPtr + start_row * imageWidth;
			threads.emplace_back
			(
				calculateSum, 
				chunk_start, 
				chunk_start + rows_to_process * imageWidth, 
				start_row, 
				rows_to_process, 
				results, 
				imageWidth
			);
		}

		for (auto& t : threads)
			t.join();
	};

	static auto CalculateSumVertically
	(
		unsigned short* const dataPtr,
		const int& imageWidth,
		const int& imageHeight,
		unsigned int* const results
	) -> void
	{
		if (!dataPtr || !results) return;
		if (!imageWidth || !imageHeight) return;

		auto calculateSum = []
		(
			const unsigned short* dataPtr,
			const int& imgWidth,
			const int& imgHeight,
			int col_index,
			unsigned int* retValue
			)
			{
				unsigned int result{};
				for (auto i{ 0 }; i < imgHeight; ++i)
				{
					auto position = i * imgWidth + col_index;
					result += dataPtr[position];
				}
				*retValue = result;
			};


#ifdef ONE_THREAD_CALCULATION
		// Calculation on the single core
		for (auto i = 0; i < imageWidth; ++i)
			calculateSum(dataPtr, imageWidth, imageHeight, i, &results[i]);
#else
		auto dataSize = imageWidth;
		auto max_threads = std::min(static_cast<int>(std::thread::hardware_concurrency()), dataSize);

		int num_threads = dataSize;
		std::vector<std::thread> threads;
		threads.reserve(max_threads);

		for (auto t = 0; t < max_threads; ++t)
		{
			threads.emplace_back([&, t]() {
				for (auto i = t; i < dataSize; i += max_threads)
				{
					calculateSum(dataPtr, imageWidth, imageHeight, i, &results[i]);
				}
				});
		}

		for (auto& t : threads)
			t.join();
#endif // _DEBUG

	};


	static auto CalculateFWHM
	(
		const unsigned int* const array,
		size_t size,
		int* bestPos = nullptr,
		unsigned int* bestSum = nullptr,
		int* worstPos = nullptr,
		unsigned int* worstSum = nullptr,
		int* fwhmMiddlePosPX = nullptr
	) -> double
	{

		if (!size) return -1.0;

		// Step 1: Find the maximum value
		auto minmaxElementIter = std::minmax_element(array, &array[size - 1]);
		auto minElementIter = minmaxElementIter.first;
		auto maxElementIter = minmaxElementIter.second;
		// Best Position and Sum
		auto bestPosition = static_cast<int>(std::distance(array, maxElementIter));
		if (bestPos) *bestPos = bestPosition;

		auto maxSum = *maxElementIter;
		if (bestSum) *bestSum = maxSum;

		// Worst Position and Sum
		auto minPos = static_cast<int>(std::distance(array, minElementIter));
		if (worstPos) *worstPos = minPos;

		auto minSum = *minElementIter;
		if (worstSum) *worstSum = minSum;

		// Step 2: Calculate the half-maximum
		double halfMax = static_cast<double>(maxSum - minSum) / 2.0 + minSum;

		if (bestPosition < 0 || bestPosition > size - 1) return -1.0;

		// Step 3: Find indices where array crosses the half-maximum
		int leftIndex = -1, rightIndex = -1;

		// Looking for the left index
		for (auto i = 0; i < bestPosition; ++i)
		{
			if (leftIndex == -1 && array[i] >= halfMax) 
			{
				leftIndex = static_cast<int>(i);
				break;
			}
		}

		// Looking for the right index
		for (auto i = size - 1; i >= bestPosition; --i)
		{
			if (leftIndex != -1 && array[i] >= halfMax) 
			{
				rightIndex = static_cast<int>(i);
				break;
			}
		}

		// Handle edge cases where the full width is not well-defined
		if (leftIndex == -1 || rightIndex == -1 || rightIndex <= leftIndex) return -1.0;

		if (fwhmMiddlePosPX) *fwhmMiddlePosPX = leftIndex + (rightIndex - leftIndex) / 2;

		// Step 4: Compute FWHM
		return static_cast<double>(rightIndex - leftIndex);
	}
}
#endif

