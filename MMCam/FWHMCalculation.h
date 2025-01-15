#pragma once
#ifndef FWHMCALCULATION_H
#define FWHMCALCULATION_H

#include <numeric>
#include <thread>
#include <vector>
#include <atomic>
#include <memory>

static auto CalculateSumHorizontally
(
	unsigned short* const dataPtr, 
	const int& imageWidth, 
	const int& imageHeight, 
	unsigned int* const results
) -> void
{
	if (!dataPtr) return;
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

#ifdef _DEBUG
	//for (auto i = 0; i < imageSize.GetHeight(); ++i)
	//{
	//	const unsigned short* chunk_start = dataPtr + i * chunk_size;

	//	const unsigned short* chunk_end = (i == num_threads - 1) ? dataPtr + imageSize.GetWidth() * imageSize.GetHeight() : chunk_start + chunk_size;
	//}

//#else
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
	const wxSize& imageSize, 
	unsigned int* const results
) -> void
{
	if (!dataPtr) return;
	if (!imageSize.GetWidth() || !imageSize.GetHeight()) return;

	auto calculateSum = []
	(
		const unsigned short* dataPtr,
		const wxSize& imgSize,
		int col_index,
		unsigned int* retValue
	)
		{
			unsigned long long result{};
			for (auto i{ 0 }; i < imgSize.GetHeight(); ++i)
			{
				result += static_cast<unsigned int>(dataPtr[i * imgSize.GetWidth() + col_index]);
			}
			*retValue = result;
		};

	
#ifdef _DEBUG
	// Calculation on the single core
	for (auto i = 0; i < imageSize.GetWidth(); ++i)
		calculateSum(dataPtr, imageSize, i, &results[i]);
#else
	auto dataSize = imageSize.GetWidth();
	auto max_threads = std::min(static_cast<int>(std::thread::hardware_concurrency()), dataSize);

	int num_threads = dataSize;
	std::vector<std::thread> threads;
	threads.reserve(max_threads);

	for (auto t = 0; t < max_threads; ++t)
	{
		threads.emplace_back([&, t]() {
			for (auto i = t; i < dataSize; i += max_threads)
			{
				calculateSum(dataPtr, imageSize, i, &results[i]);
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
	int* bestPos, 
	unsigned int* bestSum
) -> double
{

	if (!size) return -1.0;

	// Step 1: Find the maximum value
	auto maxElementIter = std::max_element(array, &array[size - 1]);
	*bestPos = static_cast<int>(std::distance(array, maxElementIter));
	*bestSum = *maxElementIter;

	// Step 2: Calculate the half-maximum
	double halfMax = static_cast<double>(*bestSum) / 2.0;

	if (*bestPos < 0 || *bestPos > size - 1) return -1.0;

	// Step 3: Find indices where array crosses the half-maximum
	int leftIndex = -1, rightIndex = -1;

	// Looking for the left index
	for (auto i = *bestPos; i >= 0; --i)
	{
		if (leftIndex == -1 && array[i] < halfMax) 
		{
			leftIndex = static_cast<int>(i + 1);
			break;
		}
	}

	// Looking for the right index
	for (auto i = *bestPos; i < size; ++i)
	{
		if (leftIndex != -1 && array[i] < halfMax) 
		{
			leftIndex = static_cast<int>(i - 1);
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

#endif

