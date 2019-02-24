class Solution:
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0:
            return 0
        index = 0
        for num in nums:
            if num > nums[index]:
                index += 1
                nums[index] = num

        return index
