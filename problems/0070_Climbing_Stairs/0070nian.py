class Solution(object):  
    def climbStairs(self,n):
        nums = [1 for i in range(n)]
        if(n==1):
            return 1
        nums[1] = 2
        for i in range(3,n+1):
            nums[i-1] = nums[i-2] + nums[i-3]
        return nums[n-1]
