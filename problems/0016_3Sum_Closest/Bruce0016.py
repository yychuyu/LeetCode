# 这不够快。

class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        nums.sort()
        ans = 0
        diff = float("inf")
        #print diff
        # 会直接输出 diff
 
        for i in range(0, len(nums)):
            start, end = i + 1, len(nums) - 1
            while start < end:
                sum = nums[i] + nums[start] + nums[end]
                if sum > target:
                    if abs(target - sum) < diff:
                        # 会直接输出 2
                        diff = abs(target - sum)
                        # 会直接输出 1
                        ans = sum
                    end -= 1
                else:
                    if abs(target - sum) < diff:
                        diff = abs(target - sum)
                        ans = sum
                    start += 1
        return ans
