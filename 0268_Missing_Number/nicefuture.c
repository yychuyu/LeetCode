#include <stdio.h>

/*����һ����һ�����飬�����
int missingNumber(int* nums, int numsSize) {    
    int i, flags[numsSize+1];

    for (i = 0; i < numsSize+1; i++) flags[i] = 0;
    for (i = 0; i < numsSize; i++) flags[nums[i]] = 1;
    for (i = 0; i < numsSize+1 && flags[i] == 1; i++);

    return i;
}*/

/*//����������һ�����������
int missingNumber(int* nums, int numsSize)
{
    unsigned long long sum = 0;
    int i;

    for (i = 0; i < numsSize; i++) {
        sum += nums[i];
    }

    return ( numsSize*(numsSize+1)/2 - sum );
}*/

//��������������ͬ���������Ϊ0��ѧϰ��
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
