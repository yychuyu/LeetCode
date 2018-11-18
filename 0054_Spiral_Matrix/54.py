
# Example 1:

# Input:
# [
#  [ 1, 2, 3 ],
#  [ 4, 5, 6 ],
#  [ 7, 8, 9 ]
# ]
# Output: [1,2,3,6,9,8,7,4,5]
# Example 2:

# Input:
# [
#   [1, 2, 3, 4],
#   [5, 6, 7, 8],
#   [9,10,11,12]
# ]
# Output: [1,2,3,4,8,12,11,10,9,5,6,7]

class Solution:
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        cell_add=1
        re=[]
        if matrix==[]:return []
        y_top,x_top=len(matrix),len(matrix[0])
        while True:
            xl=cell_add;xr=x_top-(cell_add-1);yt=cell_add;yb=y_top-(cell_add-1)
            if xl>xr or yt>yb:return re
            re.extend([matrix[yt-1][cell] for cell in range(xl-1,xr,1)])
            if yt==yb:return re
            re.extend([matrix[cell][xr-1] for cell in range(yt,yb,1)])
            if xl==xr:return re
            re.extend([matrix[yb-1][cell] for cell in range(xr-2,xl-1,-1)])
            re.extend([matrix[cell][xl-1] for cell in range(yb-1,yt-1,-1)])
            cell_add+=1