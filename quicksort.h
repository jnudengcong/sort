#ifndef GUARD_QUICKSORT_H
#define GUARD_QUICKSORT_H

#include <vector>
#include <time.h>

class QuickSortSolution
{
public:
	void quickSort(std::vector<int>& nums)
	{
		int length = nums.size();
		if (length <= 1)
			return;

		time_t t;
		srand((unsigned int)time(&t));

		quckSortCore(nums, 0, length - 1);
	}

private:
	void quckSortCore(std::vector<int>& nums, int start, int end)
	{
		if (start == end)
			return;

		int index = partition(nums, start, end);
		if (index > start)
			quckSortCore(nums, start, index - 1);

		if (index < end)
			quckSortCore(nums, index + 1, end);
	}

	int partition(std::vector<int>& nums, int start, int end)
	{
		int index = randomInRange(start, end);
		swap(&nums[index], &nums[end]);

		int small = start - 1;
		for (index = start; index < end; ++index)
		{
			if (nums[index] < nums[end])
			{
				++small;
				if (index != small)
					swap(&nums[index], &nums[small]);
			}
		}
		++small;
		swap(&nums[small], &nums[end]);

		return small;
	}

	int randomInRange(int start, int end)
	{
		return rand() % (end - start + 1) + start;
	}

	void swap(int *num1, int *num2)
	{
		int temp = *num1;
		*num1 = *num2;
		*num2 = temp;
	}
};

#endif
