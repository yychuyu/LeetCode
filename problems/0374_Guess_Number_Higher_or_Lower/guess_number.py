# The guess API is already defined for you.
# @param num, your guess
# @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
# def guess(num):

class Solution(object):
    def guessNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        low = 1
        high = n
        g = (low + high) // 2
        while low < high:
            gu = guess(g)
            if gu < 0:
                high = g
            elif gu > 0:
                low = g + 1
            else:
                break
            g = (low + high) // 2
        return g
    
        