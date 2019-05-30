/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 **/

/**
 * 参数：
 * 	nums —— 原矩阵
 *	numsSize —— 原矩阵行数
 *	numsColSize —— 原矩阵每行列数(最后一行列数可能不同)
 *	r —— 修改后行数
 *	c —— 修改后列数
 *	returnSize —— 修改后行数
 *	returnColunmSizes —— 修改后每行列数
 * 返回值：
 * 	重塑矩阵指针
 **/



/************************************************************************************************************************
 * 思路：1.先判断原矩阵中元素数量numsSize*(*numsColSize)是否等于r*c；若否，r/c为原矩阵行列；
 * 	 2.根据r/c进行双循环复制
 * TC: O(m*n)	SC: O(m*n)
 * Runtime: 32 ms, faster than 100.00% of C online submissions
 * Memory Usage: 12.8 MB, less than 44.87% of C online submissions 
 ***********************************************************************************************************************/

int** matrixReshape(int** nums, int numsSize, int* numsColSize, int r, int c, int* returnSize, int** returnColumnSizes){
	if( numsSize*(*numsColSize) != r*c )
	{
		r = numsSize;
		c = *numsColSize;	
	}
	int **returnnums = (int**) malloc(sizeof(int*) * r);
	*returnColumnSizes = (int*) malloc(sizeof(int*) * r);
	int i = 0, j = 0, row = 0, iterator = 0;
	int col = *numsColSize;	
	for( i = 0; i < r; i++ )
	{
		returnnums[i] = (int*) malloc(sizeof(int) * c);
		for( j = 0; j < c; j++ )
		{
			if( row < iterator/col )	row++;
			returnnums[i][j] = nums[row][iterator%col];
			iterator++;
		}
		(*returnColumnSizes)[i] = j;
	}
	*returnSize = r;
	return returnnums;
}




/************************************************************************************************************************
 * 参考Discussion @StefanPochmann < https://leetcode.com/problems/reshape-the-matrix/discuss/102563/C-solution >
 * 思路：1.先判断原矩阵中元素数量numsSize*(*numsColSize)是否等于r*c；若否，r/c为原矩阵行列；
 * 	 2.根据r/c但循环复制，以i计数，行下标为i/列数，列下标为i%列数
 * TC: O(m*n)	SC: O(m*n)
 * Runtime: 36 ms, faster than 100.00% of C online submissions 
 * Memory Usage: 12.8 MB, less than 55.13% of C online submissions
 ***********************************************************************************************************************/

int** matrixReshape(int** nums, int numsSize, int* numsColSize, int r, int c, int* returnSize, int** returnColumnSizes){
	if( numsSize*(*numsColSize) != r*c )
	{
		r = numsSize;
		c = *numsColSize;	
	}
	*returnSize = r;
	*returnColumnSizes = (int*) malloc(sizeof(int*) * r);
	int **returnnums = (int**) malloc(sizeof(int*) * r);
	for( int i = 0; i < r; i++ )
	{
		(*returnColumnSizes)[i] = c;
		returnnums[i] = (int*) malloc(sizeof(int) * c);
	}
	int row = numsSize, col = *numsColSize;
	int size = r*c;	
	for( int i = 0; i < size; i++ )
	{
		returnnums[i/c][i%c] = nums[i/col][i%col];
	}
	return returnnums;
}
