/*************************************************************************
	> File Name: homesong345.c
	> Author:    SKLance
	> Mail:      zhangzewu345@126.com
	> Created Time: 2018-12-06 05:39:20
 ************************************************************************/


/*************************************************************************
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
 ************************************************************************/

/**
 *  * Note: The returned array must be malloced, assume caller calls free().
 *   */
int* twoSum(int* nums, int numsSize, int target) {
    int i,j;
    int subNum = 0;
    static int p[2]={0};

    for(i=0;i<numsSize-1;i++){
        subNum = target - nums[i];
        for(j=i+1;j<numsSize;j++)
        if(nums[j] == subNum){
            p[0]=i;
            p[1]=j;
            return p;
        }
    }
    return 0;
}
