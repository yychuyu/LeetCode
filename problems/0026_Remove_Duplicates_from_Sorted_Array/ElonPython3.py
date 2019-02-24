class Solution:
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums)<2:
            return len(nums)
        diff = 1
        for index in range(1,len(nums)):
            if nums[index] !=nums[index-1]:
                nums[diff] = nums[index]
                diff = diff + 1
        return diff
