
# Example 1:

# email:fansluck@qq.com
# wechat:fanshengluck2

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
        layer=1
        re=[]
        if matrix==[]:return []
        y_top,x_top=len(matrix),len(matrix[0])
        while True:
            xr=x_top-(layer-1);yb=y_top-(layer-1)
            if layer>xr or layer>yb:return re
            elif layer==yb :
                re.extend(matrix[layer-1][layer-1:xr])
            elif layer==xr and layer<yb:
                for i in range(layer-1,yb):
                    re.append(matrix[i][layer-1])
            else:
                re.extend(matrix[layer-1][layer-1:xr])
                for cell in range(layer,yb,1):
                    re.append(matrix[cell][xr-1])
                re.extend(matrix[yb-1][xr-2:layer-1:-1])
                for cell in range(yb-1,layer-1,-1):
                    re.append(matrix[cell][layer-1])
            layer+=1