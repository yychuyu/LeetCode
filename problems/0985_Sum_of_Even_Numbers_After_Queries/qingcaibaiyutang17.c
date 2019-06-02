int* sumEvenAfterQueries(int* A, int ASize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
	int i, sum = 0, n;
	*queriesColSize = queriesSize;
	*returnSize = ASize;
	int *returnA = (int *)malloc(sizeof(int)*ASize);
	for (i = 0; i < ASize; i++) {
		if ((A[i] & 1) == 0)
			sum += A[i];
	}

	for (i = 0; i < queriesSize; i++) {
		n = A[queries[i][1]] + queries[i][0];
		if ((n & 1) == 0 && (queries[i][0] & 1) == 1)
			sum += A[queries[i][1]] + queries[i][0];
		else if ((n & 1) == 0 && (queries[i][0] & 1) == 0)
			sum += queries[i][0];
		else if ((A[queries[i][1]] & 1) == 0)
			sum -= A[queries[i][1]];
		A[queries[i][1]] = n;

		returnA[i] = sum;
	}
	return returnA;
}