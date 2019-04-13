class Solution:
    def findDiagonalOrder(self, matrix: List[List[int]]) -> List[int]:
        '''find diagonal'''
        if not matrix:
            return []
        m = len(matrix)
        n = len(matrix[0])
        signal = 1
        if m > n:
            matrix = list(zip(*matrix))
            m, n = n, m
            signal = 0
        result = []
        for summon in range(m+n-1):
            diagonal = []
            for x in range(m):
                if 0<= summon-x <n:
                    diagonal.append(matrix[x][summon-x])
            result += diagonal if summon%2==signal else diagonal[::-1]
        return result
        
        '''learn
        res = []
        lines = [[]for _ in range(m+n-1)]
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                lines[i+j].append(matrix[i][j])
        for k in range(len(matrix) + len(matrix[0]) - 1):
            if k % 2 == 0:
                res += lines[k][::-1]
            else:
                res += lines[k]
        return res
        '''     
