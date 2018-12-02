int maxSubArray(int* nums, int numsSize) {
    if(NULL == nums)
        return 0;
    int curMax = 0;
    int maxSum = -2147483647;
    int loop  = 0;
    for(loop;loop < numsSize;loop++)
    {
        if(curMax+nums[loop] > nums[loop])
            curMax = curMax+nums[loop];
        else
            curMax = nums[loop];
        if(curMax > maxSum)
            maxSum = curMax;
    }
    return maxSum;   
}
