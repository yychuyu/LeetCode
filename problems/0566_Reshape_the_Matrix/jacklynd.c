int** matrixReshape(int** nums, int numsRowSize, int numsColSize, int r, int c, int** columnSizes, int* returnSize) {
	
	int i, j, count = 0, row = 0, col = 0;
	
	int **pnums = (int**)malloc(sizeof(int *) * r);		//
	
	if(numsRowSize * numsColSize < r * c) 
	{
		r = numsRowSize;
		c = numsColSize;
	}

	for(i = 0; i < r; i++)
	{
		pnums[i] = (int *)malloc(sizeof(int) * c);
		for(j = 0; j < c; j++)
		{
			pnums[i][j] = nums[row][col++];
			if(col == numsColSize) 
			{
				col = 0;
				row += 1;
			}
		}
	}

	columnSizes[0] = (int *)malloc(sizeof(int) * r);
	for(i = 0; i < r; i++)
    {
		columnSizes[0][i] = c;
    }  
	*returnSize = r;

	return pnums;

    }