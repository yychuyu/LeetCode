#include <stdio.h>

/*方法一，用一个数组，做标记
int missingNumber(int* nums, int numsSize) {    
    int i, flags[numsSize+1];

    for (i = 0; i < numsSize+1; i++) flags[i] = 0;
    for (i = 0; i < numsSize; i++) flags[nums[i]] = 1;
    for (i = 0; i < numsSize+1 && flags[i] == 1; i++);

    return i;
}*/

/*//方法二，用一个变量，求和
int missingNumber(int* nums, int numsSize)
{
    unsigned long long sum = 0;
    int i;

    for (i = 0; i < numsSize; i++) {
        sum += nums[i];
    }

    return ( numsSize*(numsSize+1)/2 - sum );
}*/

//方法三，两数相同则异或运算为0。学习了
int missingNumber(int* nums, int numsSize)
{
    int i, result = 0;

    for (i = 0; i < numsSize; i++) {
        result ^= (i ^ nums[i]);
    }
    result ^= i;

    return result;
}

int main(void)
{
    int numsSize;
    scanf("%d", &numsSize);

    int i, nums[numsSize];
    for (i = 0; i < numsSize; i++) scanf("%d,", &nums[i]);

    printf("%d\n", missingNumber(nums, numsSize));

    return 0;
}
