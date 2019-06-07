class Solution:
    def twoSum(self, numbers, target):
        d=dict()
        for i, num in enumerate(numbers, start = 1):
            tmp = target - num
            if tmp in d:
                return sorted([i, d[tmp]])
            d[num] = i