# Easy python solution with two pointers(idx)
class Solution:
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        N = len(height)
        if N<=1:
            return None
        
        left = 0 # left idx
        right = N-1 # right idx
        water = 0
        
        while left<right: # Instead of left<=right, which can cause running time error!
            tmp_min = min(height[left], height[right])
            water = max(water, (tmp_min * (right-left)))
            while height[left]<=tmp_min and left<right:
                left += 1
            while height[right]<=tmp_min and left<right:
                right -= 1
        
        return water
        
