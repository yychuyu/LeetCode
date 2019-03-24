class Solution(object):
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        if not board:
            return False
        res = False
        for i in xrange(len(board)):
            for j in xrange(len(board[0])):
                if word[0]==board[i][j]:
                    res= res or self.search(board,word[1:],i,j)

        return res
        
    def search(self,board,word,x,y):
        tmp = board[x][y]
        board[x][y]='#'
        res = False
        if len(word)==0:
            return True
        if x > 0 and board[x-1][y]==word[0]:
            res=res or self.search(board,word[1:],x-1,y)
        if y > 0 and board[x][y-1]==word[0]:
            res=res or self.search(board,word[1:],x,y-1)
        if x < len(board)-1 and board[x+1][y]==word[0]:
            res=res or self.search(board,word[1:],x+1,y)
        if y <len(board[0])-1 and board[x][y+1]==word[0]:
            res=res or self.search(board,word[1:],x,y+1)
        board[x][y]=tmp
        return res