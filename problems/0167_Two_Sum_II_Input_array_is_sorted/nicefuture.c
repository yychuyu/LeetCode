/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int* returnArr = (int*) malloc (sizeof(int)*2);
    int i = 0, j = numbersSize-1;
    while (i < j && i >= 0 && j < numbersSize) {
        if (numbers[i]+numbers[j] < target) {
            i++;
        } else if (numbers[i]+numbers[j] > target) {
            j--;
        } else {
            returnArr[(*returnSize)++] = i+1;
            returnArr[(*returnSize)++] = j+1;
            return returnArr;
        }
    }
    return returnArr;
}
