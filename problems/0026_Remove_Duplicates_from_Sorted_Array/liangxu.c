#include <stdio.h>

int removeDuplicates(int* nums, int numsSize)
{
	int pos = 0;
	int i = 0;

    if (nums == NULL || numsSize <= 0)
		return -1;

	for (i = 1; i < numsSize; i++) {
		if (nums[i] != nums[pos])
			nums[++pos] = nums[i];
	}
	return ++pos;
}


int main()
{
	int nums[] = {0, 0, 1, 2, 2, 4, 5};
	printf("result is: %d\n", removeDuplicates(nums, sizeof(nums)/sizeof(int)));
	return 0;
}
