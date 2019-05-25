class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() < 1 || grid[0].size() < 1)
            return 0;
        vector<bool> tmp(grid[0].size(), false);
        vector<vector<bool>> visited(grid.size(), tmp);
        int count = 0;
        for(int i=0; i<grid.size(); i++)
            for(int j=0; j<grid[0].size(); j++)
                if(!visited[i][j] && grid[i][j] == '1') {
                    count++;
                    dfs(grid, visited, i, j);
                }
        
        return count;
    }
    
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j) {
        visited[i][j] = true;
        if(i-1>=0 && !visited[i-1][j] && grid[i-1][j] == '1')
            dfs(grid, visited, i-1, j);
        if(j-1>=0 && !visited[i][j-1] && grid[i][j-1] == '1')
            dfs(grid, visited, i, j-1);
        if(i+1<grid.size() && !visited[i+1][j] && grid[i+1][j] == '1')
            dfs(grid, visited, i+1, j);
        if(j+1<grid[0].size() && !visited[i][j+1] && grid[i][j+1] == '1')
            dfs(grid, visited, i, j+1);
        
        return;
    }
};
