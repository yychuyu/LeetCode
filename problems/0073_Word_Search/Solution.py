class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        
        def dfs(x, y, word):
            if len(word) == 0:
                return True
            if x > 0 and board[x-1][y] == word[0]:
                tmp = board[x][y]
                board[x][y] = '#'
                if dfs(x-1, y, word[1:]):
                    return True
                board[x][y] = tmp
            if x < len(board) - 1 and board[x+1][y] == word[0]:
                tmp = board[x][y]
                board[x][y] = '#'
                if dfs(x+1, y, word[1:]):
                    return True
                board[x][y] = tmp
            if y > 0 and board[x][y-1] == word[0]:
                tmp = board[x][y]
                board[x][y] = '#'
                if dfs(x, y-1, word[1:]):
                    return True
                board[x][y] = tmp
            if y < len(board[x]) - 1 and board[x][y+1] == word[0]:
                tmp = board[x][y]
                board[x][y] = '#'
                if dfs(x, y+1, word[1:]):
                    return True
                board[x][y] = tmp
            return False
        for i in range(len(board)):
            for j in range(len(board[i])):
                if board[i][j] == word[0]:
                    if dfs(i, j, word[1:]):
                        return True
        return False
