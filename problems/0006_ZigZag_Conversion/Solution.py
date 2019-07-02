class Solution:
    def convert(self, s, numRows):
        if numRows == 1: return s
        result = [[] for i in range(numRowns)]
        row = 0
        direct = 1
        for c in s:
            result[row].append(c)
            if row >= numRows - 1:
                direct = -1
            elif row == 0:
                direct = 1
            row += direct
        answer = ''
        for row in result:
            for col in row:
                answer += col
        return answer
