/*********************************************************
 * 给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。
 * 你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。
*********************************************************/

int* twoSum(int* nums, int numsSize, int target) {
    static int result[2];
    for (int i = 0;i<numsSize;i++)
    {
        for(int j = i+1;j<numsSize;j++)
        {
            if(nums[i]+nums[j]==target)
            {
                result[0] = i;
                result[1] = j;
            }
        } 
    }
    return result;
}
