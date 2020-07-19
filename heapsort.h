#ifndef GUARD_HEAPSORT_H
#define GUARD_HEAPSORT_H

#include <vector>

class HeapSortSolution
{
public:
	void heapSort(std::vector<int>& nums)
	{
		int length = nums.size();
		if (length <= 1)
			return;

		for (int i = length / 2 - 1; i >= 0; --i)
			heapAdjust(nums, i, length - 1);

		for (int i = length - 1; i >= 1; --i)
		{
			swap(&nums[0], &nums[i]);
			heapAdjust(nums, 0, i - 1);
		}
	}

private:
	void heapAdjust(std::vector<int>& nums, int start, int end)
	{
		int temp = nums[start];
		for (int i = start * 2 + 1; i <= end; ++i)
		{
			if (i + 1 <= end && nums[i + 1] > nums[i])
				++i;

			if (temp >= nums[i])
				break;

			nums[start] = nums[i];
			start = i;
		}
		nums[start] = temp;
	}

	void swap(int* num1, int* num2)
	{
		int temp = *num1;
		*num1 = *num2;
		*num2 = temp;
	}
};

#endif
