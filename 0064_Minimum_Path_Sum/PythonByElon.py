class Solution:
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m, n =len(grid), len(grid[0])
        for i in range(1,m):
            grid[i][0] = grid[i-1][0] + grid[i][0]
        for j in range(1,n):
            grid[0][j] = grid[0][j-1] + grid[0][j]
        
        for i in range(1,m):
            for j in range(1,n):
                grid[i][j] = grid[i][j] + min(grid[i-1][j], grid[i][j-1])
        
        return grid[-1][-1] if m*n != 0 else 0
            
