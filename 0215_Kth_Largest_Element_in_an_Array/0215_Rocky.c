static int cmpint(const void *p1, const void *p2) {
    return *(int *) p2 - *(int *) p1;
}

int findKthLargest(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), cmpint);
    return nums[k - 1];
}
