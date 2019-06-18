int findMaxConsecutiveOnes(int* nums, int numsSize){
    int maxi = 0, cnt = 0;
    for (int i=0; i<numsSize; i++) {
        if (nums[i] == 1) {
            cnt += 1;
        } else {
            if (cnt > maxi) maxi = cnt;
            cnt = 0;
        }
    }
    if (cnt > maxi) maxi = cnt;
    return maxi;
}
