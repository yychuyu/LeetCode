/*
����һ�� n ��Ԫ������ģ������������� nums ��һ��Ŀ��ֵ target  ��дһ���������� nums �е� target�����Ŀ��ֵ���ڷ����±꣬���򷵻� -1��


ʾ�� 1:

����: nums = [-1,0,3,5,9,12], target = 9
���: 4
����: 9 ������ nums �в����±�Ϊ 4
ʾ�� 2:

����: nums = [-1,0,3,5,9,12], target = 2
���: -1
����: 2 ������ nums ����˷��� -1
 

��ʾ��

1. ����Լ��� nums �е�����Ԫ���ǲ��ظ��ġ�
2. n ���� [1, 10000]֮�䡣
3. nums ��ÿ��Ԫ�ض����� [-9999, 9999]֮�䡣
*/

/***************************************************************
*   
*
*   �ļ����ƣ�0704_Binary_Search_by_persiststudy.c
*   �� �� �ߣ�persiststudy
*   �������ڣ�2018��11��19��
*   ��    ����
*
***************************************************************/

#include <stdio.h>

#define maxn 10000 + 5
int a[maxn];

int search(int* nums, int numsSize, int target)
{
    int l = 0;
    int r = numsSize - 1;
    int mid;

    while (l <= r)
    {
        mid = l + ((r - l) >> 1);
        if (nums[mid] == target)
        {
            return mid;
        }
        if (target < nums[mid])
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
}
int main()
{
    int n;
    int i;
    int target;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", a + i);
    }
    scanf("%d", &target);

    printf("%d", search(a, n, target));

    return 0;
}
