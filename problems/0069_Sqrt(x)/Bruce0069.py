class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x == 0:
            return 0
        left = 1
        right = x
        while left <= right:
            mid = (left + right) >> 1
            if mid * mid > x:
                right = mid
            elif mid * mid < x:
                if mid == left:
                    return mid
                left = mid
            else:
                return mid
        return None
		