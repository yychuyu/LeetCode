class Solution(object):
    def removeDuplicates(self, A):
        if A == []:
            return 0
        low = 0
        for i in range(1, len(A)):
            if A[low] != A[i]:
                low += 1
                A[low] = A[i]

        return low + 1
        
