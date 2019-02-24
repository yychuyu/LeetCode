class Solution:
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        dif = 0
        for i in range(len(nums)):
            if nums[i]!=val:
                nums[dif],nums[i] = nums[i],nums[dif]
                dif = dif +1
        return dif
        
