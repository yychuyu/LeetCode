#include <stdio.h>

/*方法一，用一个数组，做标记
int missingNumber(int* nums, int numsSize) {    
    int i, flags[numsSize+1];

    for (i = 0; i < numsSize+1; i++) flags[i] = 0;
    for (i = 0; i < numsSize; i++) flags[nums[i]] = 1;
    for (i = 0; i < numsSize+1 && flags[i] == 1; i++);

    return i;
}*/

//方法二，用一个变量，求和
int missingNumber(int* nums, int numsSize)
{
    unsigned long long sum = 0;
    int i;

    for (i = 0; i < numsSize; i++) {
        sum += nums[i];
    }

    return ( numsSize*(numsSize+1)/2 - sum );
}

//两种方法耗时都不算长，占用内存空间大小不同

int main(void)
{
    int numsSize;
    scanf("%d", &numsSize);

    int i, nums[numsSize];
    for (i = 0; i < numsSize; i++) scanf("%d,", &nums[i]);

    printf("%d\n", missingNumber(nums, numsSize));

    return 0;
}
