class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int> > g(grid.size());
        for (int i = 0; i < grid.size(); ++i) {
            g[i].resize(grid[i].size());
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == '1') {
                    g[i][j] = 0;
                } else {
                    g[i][j] = -1;
                }
            }
        }
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (!g[i][j]) {
                    mark(g, i, j);
                    cout << "------------\n";
                    tot++;
                }
            }
        }
        return tot-1;
    }
private:
    int  tot = 1;
    void mark(vector<vector<int> >& g, int i, int j) {
        cout << i << "\t" << j << endl;
        g[i][j] = tot;
        if (i+1<g.size() && !g[i+1][j]) {
            mark(g, i+1, j);
        }
        if (j+1< g[i].size() && !g[i][j+1]) {
            mark(g, i, j+1);
        }
        if (j-1 > -1 && !g[i][j-1]) {
            mark(g, i, j-1);
        }
        if (i-1 > -1 && !g[i-1][j]) {
            mark(g, i-1, j);
        }
    }
};
