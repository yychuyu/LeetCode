class Solution(object):
    def findDiagonalOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        if not matrix:
            return []
        try:
            matrix[0][0]
        except:
            return len(matrix)
        n = len(matrix)
        m = len(matrix[0])
        res = [0] * (m * n)
        i, j = 0, 0
        for linearIndx in range(m * n):
            diagIndx = i + j
            res[linearIndx] = (matrix[i][j])
            if diagIndx % 2 == 0:
                j = j + 1
                if j == m:
                    i, j = i + 1, m - 1
                else:
                    i = max(i - 1, 0)
            else:
                i += 1
                if i == n:
                    i, j = n - 1, j + 1
                else:
                    j = max(0, j - 1)
        return res


if __name__ == '__main__':
    lis = [[1, 2, 3, 4], [5, 6, 7, 8]]
    # lis = [1, 2, 3, 4, 5, 6, 7, 8]
    s = Solution()
    print(s.findDiagonalOrder(lis))
