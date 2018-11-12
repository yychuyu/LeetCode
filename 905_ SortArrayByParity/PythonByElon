class Solution(object):
    def sortArrayByParity(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        60ms
        86%
        """
        left = 0
        right = len(A) - 1
        
        while left < right:
            if A[left] % 2 == 0:
                left = left + 1
            elif A[right] % 2 == 1:
                right = right - 1 
            else :
                A[left],A[right] = A[right],A[left]
                left = left + 1
                right = right - 1
        return A
            
