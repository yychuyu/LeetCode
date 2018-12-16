int removeElement(int* nums, int numsSize, int val) {
    for (int i=0; i<numsSize; i++) {
        if (nums[i] == val) {
            nums[i] = nums[numsSize-1];
            numsSize--;
            i--;
        }
    }
    return numsSize;
}
