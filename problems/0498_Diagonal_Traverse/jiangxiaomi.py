class Solution:
    def findDiagonalOrder(self, matrix: List[List[int]]) -> List[int]:
        m = len(matrix)
        if m == 0:
           return []
        n = len(matrix[0])
        result =[]
        if m >= n:
            flag = n
            minus = m-n+1
            resultList = getCountlist(flag,minus)
            k = 0
            for i in resultList:
                result_tmp = []
                if k >= m:
                    for j in range(i):
                        result_tmp.append(matrix[m-j-1][flag-i+j])
                else:
                    for j in range(i):
                        result_tmp.append(matrix[k-j][j])
                if k % 2 != 0:
                    result_tmp.reverse()
                result = result+result_tmp
                k += 1
        else:
            flag = m
            minus = n-m+1
            resultList = getCountlist(flag, minus)
            k = 0
            for i in resultList:
                result_tmp = []
                if k >= n:
                    for j in range(i):
                        result_tmp.append(matrix[flag - i + j][n - j - 1])
                else:
                    for j in range(i):
                        result_tmp.append(matrix[j][k-j])
                if k % 2 == 0:
                    result_tmp.reverse()
                result = result + result_tmp
                k += 1
        return result


def getCountlist(flag, minus):
    result_1 = [i for i in range(1, flag)]
    result_2 = [flag for _ in range(minus)]
    result_3 = result_1.copy()
    result_3.reverse()
    return result_1+result_2+result_3