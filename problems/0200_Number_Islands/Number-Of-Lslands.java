class Solution {
    public int numIslands(char[][] grid) {
        int res = 0;
	if (grid == null || grid.length == 0 || grid[0].length == 0)
		return res;
	int m = grid.length;
	int n = grid[0].length;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == '1') {
				bfs(grid, i, j);
				res += 1;
			}
		}
	}
	return res;
    }
    
    protected static void bfs(char[][] grid, int i, int j) {
	//代表上下左右方向
	int[][] dir = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
	int m = grid.length;
	int n = grid[0].length;
	Queue<Integer> q = new LinkedList<Integer>();
	grid[i][j] = '0';
	q.add(i * n + j);

	while (!q.isEmpty()) {
		int cur = q.poll();
		int x = cur / n;
		int y = cur % n;
		for (int k = 0; k < 4; k++) {
			int nextX = x + dir[k][0];
			int nextY = y + dir[k][1];
			//将所有一步可达的点置为'0' 并加入queue中，以访问它们可达的点
			if (nextX >= 0 && nextY >= 0 && nextX < m 
				&& nextY < n && grid[nextX][nextY] == '1') {
				grid[nextX][nextY] = '0';
				q.add(nextX * n + nextY);
			}
		}
	}
}
}
