/**
* LeetCode The 26th problem :remove-duplicates-from-sorted-array
* Auth:Barlowwang
* Date:2018-10-08
**/ 
int removeDuplicates(int *nums, int numsSize)
{
    if (numsSize == 0)
        return 0;
    int current = 0;
    for (int i = 0; i < numsSize; ++i)
    {
        if (nums[i] != nums[current])
        {
            nums[++current] = nums[i];
        }
    }
    return current + 1;
}