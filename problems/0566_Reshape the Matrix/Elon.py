class Solution(object):
    def matrixReshape(self, nums, r, c):
        """
        :type nums: List[List[int]]
        :type r: int
        :type c: int
        :rtype: List[List[int]]
        """
    #code by Elon
        flat = sum(nums,[])
        result = []
        if len(flat)==r*c:
            for index in range(r):
                result.append(flat[index*c:index*c+c])
            return result
        else :  return nums