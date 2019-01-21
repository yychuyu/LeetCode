int singleNumber(int* nums, int numsSize) {
    int s = 0;
    for (int i = 0; i < numsSize; i++) {
        s ^= nums[i];
    }
    return s;
}
