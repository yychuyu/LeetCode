class Solution:
    def reverse(self, x):
        if x > 0:
            nums = str(x)[::-1]
        else:
            nums =  '-' + str(-x)[::-1]    
        if int(nums) < 2**31-1 and int(nums) > -2**31:
            return int(nums)
        else:
            return 0