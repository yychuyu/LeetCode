

/*
给定两个有序数组nums1,nums2,将nums2合并到nums1中，使得nums1成为一个有序数组
（nums1有足够大的空间）


*/

#include <stdio.h>
#include <stdlib.h>


void printArr(int *arr, int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		printf("%d,", *(arr + i));
	}
}

//这里默认从小到大的顺序
//Solution 1:使用额外的空间
void merge(int *nums1, int m, int *nums2, int n)
{	
	int newLength = m + n;
	int* saveArr = (int *)malloc(sizeof(int)*newLength);
	int curIndex = 0;
	int i=0, j = 0;

	while (curIndex < newLength)
	{
		if (i < m && j < n)
		{

			if (nums1[i] < nums2[j])
			{
				saveArr[curIndex] = nums1[i];
				i++;

			}
			else
			{
				saveArr[curIndex] = nums2[j];
				j++;
			}
		}
		else 
		{
			if (i >= m)
			{
				saveArr[curIndex] = nums2[j];
				j++;
			}
			else
			{
				saveArr[curIndex] = nums1[i];
				i++;
			}

		}

		curIndex++;
	}

	printArr(saveArr, newLength);
	system("pause");
}

void main()
{
	int arr1[] = { 1, 4 ,7,8,10};
	int arr2[] = { 2, 5, 6, 8, 10, 12 };

	int arr1Length = sizeof(arr1) / sizeof(int);
	int arr2Length = sizeof(arr2) / sizeof(int);

	merge(arr1, arr1Length, arr2, arr2Length);
}


