#include <stdio.h>
#include "malloc.h"


/*
思路是建立一个map数组，map元素是nums对应的元素的下标，map下标为
nums元素与nums最小值的差。
距离的原点设为nums最小值而不是直接使用0，是考虑到负数情况。
*/
int* twoSum(int* nums, int numsSize, int target) {
	int i, min = nums[0], max = nums[0];
	//找出最大值和最小值
	for (i = 0; i < numsSize; i++) {
		if (nums[i] > max) max = nums[i];
		if (nums[i] < min) min = nums[i];
	}
	//因为map的下标为距离，因此map的大小设为最大距离+1即可。
	int *map = (int*)calloc((max - min + 1), sizeof(int));
	int *twosum = (int*)malloc(sizeof(int) * 2);
	// 每扫描一个nums元素，将该元素的下标和距离记录在map中
	for (i = 0; i < numsSize; map[nums[i] - min] = ++i) {
		int lookfornum = target - nums[i];
		if (lookfornum<min || lookfornum>max)
			continue;
		int dis = lookfornum - min;
		// 判断目标距离上是否已经存有数值
		if (map[dis] != 0) {
			twosum[0] = i;
			twosum[1] = map[dis] - 1;
			break;
		}
	}

	return twosum;
}