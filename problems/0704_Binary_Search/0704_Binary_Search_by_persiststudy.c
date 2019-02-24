/*
给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。


示例 1:

输入: nums = [-1,0,3,5,9,12], target = 9
输出: 4
解释: 9 出现在 nums 中并且下标为 4
示例 2:

输入: nums = [-1,0,3,5,9,12], target = 2
输出: -1
解释: 2 不存在 nums 中因此返回 -1
 

提示：

1. 你可以假设 nums 中的所有元素是不重复的。
2. n 将在 [1, 10000]之间。
3. nums 的每个元素都将在 [-9999, 9999]之间。
*/

/***************************************************************
*   
*
*   文件名称：0704_Binary_Search_by_persiststudy.c
*   创 建 者：persiststudy
*   创建日期：2018年11月19日
*   描    述：
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
