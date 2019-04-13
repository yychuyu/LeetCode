class Solution:
    def numEnclaves(self, A: List[List[int]]) -> int:
        def findOnes(i, j):
            A[i][j] = 0
            for x, y in (i - 1, j), (i, j - 1), (i + 1, j), (i, j + 1):
                if 0 <= x < m and 0 <= y < n and A[x][y] == 1:
                    findOnes(x, y)
        m, n = len(A), len(A[0])
        for i in range(m):
            for j in range(n):
                if (i == 0 or i == m-1 or j == 0 or j == n-1) and A[i][j] == 1:
                    findOnes(i,j)
        return sum(sum(row) for row in A)