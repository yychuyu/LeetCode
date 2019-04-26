class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        cot = 0
        while 0 in nums:
            nums.remove(0)
            cot += 1
        while cot:
            nums.append(0)
            cot -= 1
