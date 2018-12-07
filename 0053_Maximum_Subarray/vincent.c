/************************************************************************
 * 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），
 * 返回其最大和。
*************************************************************************/

//感谢torresng的思路

#include <stdio.h>

int maxSubArray(int* nums, int numsSize);

int main()
{
    int nums[10] = {-2,1,-3,4,-1,2,1,-5,4};
    printf("%d",maxSubArray(nums,9));
    return 0;
}


int maxSubArray(int* nums, int numsSize) {
    int i=0, sum=-2147483647, max=0;
    for(i=0;i<numsSize;i++)
    {
        if(max + nums[i] > nums[i])
            max = max + nums[i];
        else max = nums[i];
        
        if(max > sum) sum = max;
        
        
        
        
    }
    return sum;
    
    
    
    
}