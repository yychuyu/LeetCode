class Solution(object):
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        far = 0
        for i in range(len(nums)):
            far = max(nums[i]+i,far)
            if(i>=far):
                break
        if(far>=len(nums)-1):
            return True
        else:
            return False
