/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int* result = (int*) malloc((digitsSize+1) * sizeof(int));
    int n = digitsSize - 1, add = 1;
            
    while (n >= 0) {
        int digit = digits[n] + add;
        if (digit > 9) {
            result[n+1] = digit % 10;
            add = digit / 10;
        } else {
            result[n+1] = digit;
            add = 0;
        }
        n--;
        (*returnSize)++;
    }
    if (add) {
        result[0] = add;
        ++(*returnSize);
    } else {
        result++;
    }
    
    return result;
}
