# 主要使用hash表的快速查找特性
# 把双重循环转化成单层循环

class Solution:
    def twoSum(self, nums, target):
        num_dict = {nums[i]: i for i in range(nums)}

        for i in range(len(nums)):
            component = target - nums[i]
            if component in num_dict and num_dict[component] != i:
                return [i, num_dict[component]]
