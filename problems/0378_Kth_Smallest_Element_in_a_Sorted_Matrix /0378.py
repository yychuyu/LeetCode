class Solution(object):
    def kthSmallest(self, matrix, k):
        """
        :type matrix: List[List[int]]
        :type k: int
        :rtype: int
        """
        r_list = []
        for i in range(len(matrix)):
            for j in range(len(matrix)):
                r_list.append(matrix[i][j])
        r_list.sort()
        
        return r_list[k - 1]