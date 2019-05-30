int maxSubArray(int* nums, int numsSize){
    int result = nums[0], s = nums[0];
    for (int i=1; i<numsSize; i++) {
        s += nums[i];
        if (s < nums[i]) s = nums[i];
        if (s > result) result = s;
    }
    return result;
}
