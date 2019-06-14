# 本题有两种解法，分别是动态规划和分而治之
# 动态规划，主要是定义一个dp数组，用来保存到index为止,数组的子序列的和
# dp[0]等于数组的第一个元素的值，从数组第一个元素开始，其下标为i,如果dp[i-1] > 0,那么dp[i]=dp[i-1] + nums[i], 如果dp[i-1] < 0,那么dp[i]=nums[i]
# 在计算dp数组的时候，记录每次子序列和的最大值，该最大值就是所求子序列和的最大值
class solution:
    def maxSubArray(self, nums):
        if not nums:
            return 0
        dp = len(nums) * [0]
        sub_max = dp[0] = nums[0]

        for i in range(1, len(nums)):
            if dp[i-1] > 0:
                dp[i] = dp[i-1] + nums[i]
            else:
                dp[i] = nums[i]
            sub_max = max(dp[i], sub_max)
        return sub_max

# 分而治之的方式，主要是利用二分的方式，把数组一分为二，首先求出左边子数组的最大和，然后再求出右边子数组的最大和，然后从中间元素开始，
# 进行遍历求出当前子序列的最大和
class Solution:
    def maxSubArray(self, nums):
        def find_max(nums, left, right):
            if left >= right:
                return nums[left]

            center = (left + right) // 2
            lmax = find_max(nums, left, center - 1)
            rmax = find_max(nums, center + 1, right)
            t = mmax = nums[center]

            for i in range(center - 1, left - 1, -1):
                t += nums[i]
                mmax = max(t, mmax)
            t = mmax
            
            for i in range(center + 1, right, 1):
                t += nums[i]
                mmax = max(t, mmax)
            return max(mmax, lmax, rmax)

        if not nums:
            return 0
        else:
            return find_max(nums, 0, len(nums) - 1)
