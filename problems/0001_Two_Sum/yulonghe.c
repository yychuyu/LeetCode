/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int i, j;
    int *p;
    
    p = (int *)malloc(2*sizeof(int));
    for(i=0; i<numsSize-1; i++)
    {
        for(j=1+i; j<numsSize; j++)
        {
            if(*(nums+i)+*(nums+j) == target)
            {
                *p = i;
                *(p+1) = j;
                return p;
            }
        }
    }
    return p;
}
