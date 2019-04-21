#include<stdio.h>
#include<malloc.h>
/*
同一个测试用例，本地测试没有问题，leetcode运行出错，感觉可能是leetcode有点问题，因为使用评论里
别人的代码会报同样的错
*/
/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
int* findDiagonalOrder(int** matrix, int matrixRowSize, int matrixColSize, int* returnSize) {
	int *res = (int *)malloc(sizeof(int) * matrixRowSize * matrixColSize);
	bool dir = 1;
	int m = 0, n = 0;
	*returnSize = 0;
	while (m < matrixRowSize  && n < matrixColSize) {
		printf("m=%d, n=%d\n", m, n);
		res[(*returnSize)++] = *((int*)matrix + m*matrixColSize + n);
		if (dir) {
			if (n == matrixColSize - 1) {
				dir = 0;
				m++;
			}
			else if (m == 0) {
				dir = 0;
				n++;
			}
			else {
				m--;
				n++;
			}
		}
		else {
			if (m == matrixRowSize - 1) {
				dir = 1;
				n++;
			}
			else if (n == 0) {
				dir = 1;
				m++;
			}
			else {
				m++;
				n--;
			}
		}
	}
	return res;
}

int main() {
	int a[3][3] = { {1,2,3},{4,5,6},{ 7,8,9 } };
	int *res;
	int returnSize = 0;
	res = findDiagonalOrder((int**)a, 3, 3, &returnSize);
	return 0;
}