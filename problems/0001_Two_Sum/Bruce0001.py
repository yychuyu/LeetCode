class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        input = {}
        for index, num in enumerate(nums):
            other = target - num
            if other in input:
                return [input[other], index]
            else:
                input[num] = index
        return []
		
        