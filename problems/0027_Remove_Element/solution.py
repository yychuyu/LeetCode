class Solution:
    def removeElement(self, nums, val):
        i = 0
        while i < len(nums):
            if nums[i] == val:
                nums[i:] = nums[i+1:]
            else:
                i += 1
        return len(nums)