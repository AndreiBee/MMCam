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
			int row_index,
			unsigned int* results
			)
			{
				auto result = std::accumulate(start, end, 0);
				results[row_index] = result;
			};

#ifdef ONE_THREAD_CALCULATION
		//for (auto i = 0; i < imageSize.GetHeight(); ++i)
		//{
		//	const unsigned short* chunk_start = dataPtr + i * chunk_size;

		//	const unsigned short* chunk_end = (i == num_threads - 1) ? dataPtr + imageSize.GetWidth() * imageSize.GetHeight() : chunk_start + chunk_size;
		//}

#else
		auto dataSize = imageHeight;

		int num_threads = dataSize;
		std::vector<std::thread> threads;
		threads.reserve(num_threads);
		// Split the data into chunks and process each chunk in a separate thread
		int chunk_size = imageWidth;

		for (auto i = 0; i < num_threads; ++i)
		{
			auto chunk_start = dataPtr + i * chunk_size;
			auto chunk_end = (i == num_threads - 1) ? dataPtr + imageWidth * imageHeight : chunk_start + chunk_size;
			threads.emplace_back
			(
				calculateSum,
				chunk_start,
				chunk_end,
				i,
				results
			);
		}

		for (auto& t : threads)
			t.join();
#endif // _DEBUG
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
			//auto data_start = &dataPtr[i];
			//threads.emplace_back
			//(
			//	calculateSum,
			//	dataPtr,
			//	imageSize,
			//	i,
			//	results
			//);
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
		unsigned int* worstSum = nullptr
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

		auto minSum = *maxElementIter;
		if (worstSum) *worstSum = minSum;

		// Step 2: Calculate the half-maximum
		double halfMax = static_cast<double>(maxSum - minSum) / 2.0 + minSum;

		if (bestPosition < 0 || bestPosition > size - 1) return -1.0;

		// Step 3: Find indices where array crosses the half-maximum
		int leftIndex = -1, rightIndex = -1;

		// Looking for the left index
		for (auto i = bestPosition; i >= 0; --i)
		{
			if (leftIndex == -1 && array[i] < halfMax)
			{
				leftIndex = static_cast<int>(i + 1);
				break;
			}
		}

		// Looking for the right index
		for (auto i = bestPosition; i < size; ++i)
		{
			if (leftIndex != -1 && array[i] < halfMax)
			{
				rightIndex = static_cast<int>(i - 1);
				break;
			}
		}

		//for (auto i = 0; i < size; ++i) 
		//{
		//	if (leftIndex == -1 && array[i] >= halfMax) 
		//	{
		//		leftIndex = static_cast<int>(i);
		//	}
		//	if (leftIndex != -1 && array[i] < halfMax) 
		//	{
		//		rightIndex = static_cast<int>(i - 1);
		//		break;
		//	}
		//}

		// Handle edge cases where the full width is not well-defined
		if (leftIndex == -1 || rightIndex == -1 || rightIndex <= leftIndex) return -1.0;

		// Step 4: Compute FWHM
		return static_cast<double>(rightIndex - leftIndex);
	}
}
#endif

