class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        result = []
        length = len(nums)
        for i in range(length - 1):
            num = target - nums[i]
            if num in nums:
                j = list(reversed(nums)).index(num)
                result = [i, j]
        return result


if __name__ == '__main__':
    calculator = Solution()
    calculator.twoSum(nums=[2, 7, 11, 15], target=9)

# 先正序，避免重复，再倒序求出索引
