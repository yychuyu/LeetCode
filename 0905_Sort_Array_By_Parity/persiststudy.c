/*
����һ���Ǹ��������� A������һ���� A ������ż��Ԫ����ɵ����飬����� A ����������Ԫ�ء�

����Է���������������κ�������Ϊ�𰸡�

 

ʾ����

���룺[3,1,2,4]
�����[2,4,3,1]
��� [4,2,3,1]��[2,4,1,3] �� [4,2,1,3] Ҳ�ᱻ���ܡ�
 

��ʾ��

1 <= A.length <= 5000
0 <= A[i] <= 5000
*/


/***************************************************************
*   
*
*   �ļ����ƣ�0905_sort_array_by_parity
*   �� �� �ߣ�persiststudy
*   �������ڣ�2018��11��12��
*   ��    ����
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


