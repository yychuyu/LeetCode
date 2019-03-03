/*
给定一个非负整数数组 A，返回一个由 A 的所有偶数元素组成的数组，后面跟 A 的所有奇数元素。

你可以返回满足此条件的任何数组作为答案。

 

示例：

输入：[3,1,2,4]
输出：[2,4,3,1]
输出 [4,2,3,1]，[2,4,1,3] 和 [4,2,1,3] 也会被接受。
 

提示：

1 <= A.length <= 5000
0 <= A[i] <= 5000
*/


/***************************************************************
*   
*
*   文件名称：0905_sort_array_by_parity
*   创 建 者：persiststudy
*   创建日期：2018年11月12日
*   描    述：
*
***************************************************************/

#include <stdio.h>
#include <stdlib.h>


/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* A, int ASize, int* returnSize)
{
    int i = 0;
    int j = ASize - 1;
    int *p = (int *)malloc(sizeof(int) * ASize);
    int *pLeft = p;
    int *pRight = p + ASize - 1;

    while (i <= j)
    {
        if (!(A[i] & 1))
        {
            *pLeft++ = A[i++];
            continue;
        }
        if (A[j] & 1)
        {
            *pRight-- = A[j--];
            continue;
        }
        *pLeft++ =  A[j--];
        *pRight-- = A[i++];
    }
    *returnSize = ASize;
    return p;
}



int main()
{
    int n;
    int m;
    int a[5000+5];

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
    }

    int *p = sortArrayByParity(a, n, &m);
    for (int i = 0; i < m; i++)
    {
        printf("%d ", *(p + i));
    }
    printf("\n");
    free(p);
}


