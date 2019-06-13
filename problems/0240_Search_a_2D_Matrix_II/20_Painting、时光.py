class Solution:
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """

        if len(matrix) == 0 or len(matrix[0]) == 0:
            return False


        row_num = len(matrix)
        col_num = len(matrix[0])
        start = 0

        if row_num == col_num:
            return self.findNum(matrix, target)
        elif row_num > col_num:
            while start+col_num <= row_num:
                #end_i = start+col_num if start+col_num <= row_num else row_num
                result = self.findNum(matrix[start:start+col_num], target)
                if result:
                    return True
                start += col_num
                if start == row_num:
                    return False
            for i in range(start, row_num):
                for j in range(col_num):
                    if matrix[i][j] == target:
                        return True
            
        elif col_num > row_num:
            while start+row_num <= col_num:
                #end_i = start+row_num if start+row_num <= col_num else col_num
                result = self.findNum([matrix[i][start:start+row_num] for i in range(row_num)], target)
                if result:
                    return True
                start += row_num
                if start == col_num:
                    return False
            for i in range(row_num):
                for j in range(start, col_num):
                    if matrix[i][j] == target:
                        return True

        return False

    def findNum(self, matrix, target):
        for i in range(len(matrix)):
            if matrix[i][i] == target:
                return True
            elif matrix[i][i] > target:
                break

        for k in range(i, len(matrix)):
            for j in range(k)[::-1]:
                if matrix[k][j] == target or matrix[j][k] == target:
                    return True
                # if matrix[k][j] < target and matrix[j][k] < target:
                #     return False

        return False


MATRIX = [
  [1,   4,  7, 11, 15,21,25],
  [2,   5,  8, 12, 19,30,31]
]

MATRIX = [
  [1, 4],
  [2, 5],
  [3, 6],
  [4, 7],

]

MATRIX = [[1,2,3,4,5],[6,7,8,9,10],[11,12,13,14,15],[16,17,18,19,20],[21,22,23,24,25]]
sol = Solution()
print(sol.searchMatrix(MATRIX, 15))


# ***************************************************
"""
我的想法很复杂，虽说最后提交的成绩还可以？？

以正方形为单位进行查找
首先在对角线上进行搜索，从左上开始，比target小就找下一个对角线上的元素（即前一个方形的元素全部pass）
找到比target大的元素，就搜索当前列和当前行
如果没有，搜索下一个对角线元素对应的列和行，直到遍历完整个正方形
bug：一开始有这个想法的时候是，想着到了比target小的那个地方，就只搜寻当前列和当前行就ok，
后来发现有问题，下一个行列仍可能存在对应的元素

之后就是针对行列不等的矩阵，分成很多的紧密排列的正方形正方形进行查找
最后剩下的矩形直接暴力搜索（还有一种想法是把前面几行/列加过来拼成一个正方形进行查找）
时间复杂度 最差O(m*n) 和暴力搜索没差。。。
"""

"""
被大神的思路折服=。=
其实并不难，甚至很好理解，代码也简单。。。
就是多思考，找到其内在的规律

思路：在这个矩阵中，当前元素【上小右大】，因此只需从左下或右上开始搜索，
比如从左下开始，比target大往上走，比target小往右走
时间复杂度O(m+n)
"""

