class Solution {
    public int numRookCaptures(char[][] board) {
        int rowNum = board.length;
        int columnNum = board[0].length;
        int x = 0, y = 0, sum = 0;
        //找到 R 的位置
        for (int i = 0; i < rowNum; i++) {
            for (int j = 0; j < columnNum; j++) {
                System.out.print(board[i][j] + " ");
                if(board[i][j] == 'R'){
                    x = j;
                    y = i;
                }
            }
        }
        //横向分别向左右找黑子
        for (int i = x -1; i >= 0; i--) {
            if(board[y][i] == 'B'){
                break;
            }else if(board[y][i] == 'p'){
                sum++;
                break;
            }
        }
        for (int i = x + 1; i < columnNum; i++) {
            if(board[y][i] == 'B'){
                break;
            }else if(board[y][i] == 'p'){
                sum++;
                break;
            }
        }
        //纵向分别向左右找黑子
        for (int i = y -1; i >= 0; i--) {
            if(board[i][x] == 'B'){
                break;
            }else if(board[i][x] == 'p'){
                sum++;
                break;
            }
        }
        for (int i = y + 1; i < columnNum; i++) {
            if(board[i][x] == 'B'){
                break;
            }else if(board[i][x] == 'p'){
                sum++;
                break;
            }
        }
        return sum;
    }
}