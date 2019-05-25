class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word.size() < 1)
            return true;
        if(board.size() < 1 || board[0].size() < 1)
            return false;
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[i].size(); ++j) {
                if(word[0] == board[i][j]) {
                    if(search_next(i, j, 1, word, board))
                        return true;
                }
            }
        }
        return false;
    }
    
    bool search_next(int i, int j, int index, string& word, vector<vector<char>>& board) {
        if(index == word.size())
            return true;
        char tmp = board[i][j];
        board[i][j] = '*';
        
        if(i - 1 >= 0 && word[index] == board[i-1][j]) {
            if(search_next(i-1, j, index+1, word, board))
                return true;
        }
        if(j - 1 >= 0 && word[index] == board[i][j-1]) {
            if(search_next(i, j-1, index+1, word, board))
                return true;
        }
        if(i + 1 < board.size() && word[index] == board[i+1][j]) {
            if(search_next(i+1, j, index+1, word, board))
                return true;
        }
        if(j + 1 < board[0].size() && word[index] == board[i][j+1]) {
            if(search_next(i, j+1, index+1, word, board))
                return true;
        }
        
        board[i][j] = tmp;
        return false;
    }
};
