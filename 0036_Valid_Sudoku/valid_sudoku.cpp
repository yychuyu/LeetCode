/*
  题目：
  判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。
  1. 数字 1-9 在每一行只能出现一次。
  2. 数字 1-9 在每一列只能出现一次。
  3. 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。

  数独部分空格内已填入了数字，空白格用 '.' 表示。
  
  参考：
  https://www.cnblogs.com/ganganloveu/p/4170632.html
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {        
        for(int i=0;i<9;i++){
            set<char> row;
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    if( row.find(board[i][j])==row.end() ){
                        row.insert(board[i][j]);
                    }else{                    
                        return false;                
                    }                              
                } 
            }                    
        }
        for(int i=0;i<9;i++){
            set<char> column;
            for(int j=0;j<9;j++){
                if(board[j][i]!='.'){
                    if( column.find(board[j][i])==column.end() ){
                        column.insert(board[j][i]);
                    }else{
                        return false;
                    }
                }
            }
        }
        for(int i=0;i<9;i++){//第i个九宫格
            set<char> sudoku;
            for(int j=0;j<9;j++){//第j个格
                char c=board[i/3*3+j/3][i%3*3+j%3];
                if( c!='.'){
                    if( sudoku.find(c)==sudoku.end() ){
                        sudoku.insert(c);
                    }else{
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
};
