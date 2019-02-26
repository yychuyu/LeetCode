/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

static int cmpint(const void *p1, const void *p2) {
    return *(int *) p1 - *(int *) p2;
}


int** threeSum(int* nums, int numsSize, int* returnSize) {
    int i, j, *k;
    int offset;
    
    int **result = (int **) malloc(8880000 * sizeof(int *));
    *returnSize = 0;
    
    qsort(nums, numsSize, sizeof(int), cmpint);
    
    if (nums[0] == 0 && nums[numsSize-1] == 0 && numsSize > 2) {
        result[0] = (int *) malloc(sizeof(int) * 3);
        result[0][0] = 0;
        result[0][1] = 0;
        result[0][2] = 0;
        (*returnSize)++;
        return result;
    }
    
    for (i = 0; i < numsSize - 2; i++) {
        for (j = i + 1; j < numsSize - 1; j++) {
            offset = -nums[j] - nums[i];
            if (offset < nums[j]) {
                break;
            }
            k = (int *) bsearch(&offset, nums + j + 1, numsSize - j - 1, sizeof(int), cmpint);
            if (k != NULL) {
                result[*returnSize] = (int *) malloc(sizeof(int) * 3);
                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[j];
                result[*returnSize][2] = *k;
                (*returnSize)++;
            }
            while (nums[j + 1] == nums[j])
                j++;
        }
        while (nums[i + 1] == nums[i])
            i++;
    }
    return result;
    
}
