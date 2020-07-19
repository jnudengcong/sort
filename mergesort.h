#ifndef GUARD_MERGESORT_H
#define GUARD_MERGESORT_H

#include <vector>

class MergeSortSolution
{
public:
	void mergeSort(std::vector<int>& nums)
	{
		int length = nums.size();
		if (length <= 1)
			return;

		mergeSortCore(nums, nums, 0, length - 1);
	}

private:
	void mergeSortCore(std::vector<int>& src, std::vector<int>& dst, int start, int end)
	{
		if (start == end)
		{
			dst[start] = src[end];
			return;
		}

		std::vector<int> temps(src.size());
		int middle = (start + end) / 2;
		mergeSortCore(src, temps, start, middle);
		mergeSortCore(src, temps, middle + 1, end);
		merge(temps, dst, start, middle, end);
	}

	void merge(std::vector<int>& src, std::vector<int>& dst, int start, int middle, int end)
	{
		int i = start;
		int j = middle + 1;
		int k;
		for (k = start; i <= middle && j <= end; ++k)
		{
			if (src[i] < src[j])
				dst[k] = src[i++];
			else
				dst[k] = src[j++];
		}

		if (i <= middle)
		{
			for (int l = 0; i + l <= middle; ++l)
				dst[k + l] = src[i + l];
		}

		if (j <= end)
		{
			for (int l = 0; j + l <= end; ++l)
				dst[k + l] = src[j + l];
		}
	}
};

#endif
