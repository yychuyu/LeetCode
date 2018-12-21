int searchInsert(int* nums, int numsSize, int target) {
    int lower = 0, ceiling = numsSize-1;
    while (lower <= ceiling) {
        int middle = (lower+ceiling) / 2;
        if (target < nums[middle]) {
            ceiling = middle - 1;
        } else if (target > nums[middle]) {
            lower = middle + 1;
        } else {
            return middle;
        }
    }
    return ceiling + 1;
}
