//url: https://leetcode.com/problems/word-search/
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (dfs(board, word, 0, i, j, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, string word, int index, int x, int y, vector<vector<bool>>& visited) {
        if (index == word.size()) {
            return true;
        }
        if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size()) {
            return false;
        }
        if (visited[x][y]) {
            return false;
        }
        if (board[x][y] != word[index]) {
            return false;
        }
        visited[x][y] = true;
        bool result = dfs(board, word, index + 1, x - 1, y, visited) || dfs(board, word, index + 1, x + 1, y, visited) || dfs(board, word, index + 1, x, y - 1, visited) || dfs(board, word, index + 1, x, y + 1, visited);
        visited[x][y] = false;
        return result;
    }
};
