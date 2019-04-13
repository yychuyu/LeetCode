class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        dic = {}
        for i in range(len(nums)):
            if target - nums[i] in dic.keys():
                return [dic[target - nums[i]], i]
            dic[nums[i]] = i


if __name__ == '__main__':
    haha = Solution()
    print(haha.twoSum([1, 2, 3, 4, 5, 6, 7], 11))
