class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        if(n<=2):
            return n
        count = 1
        result = 1
        for i in range(1,n):
            if(nums[i-1]==nums[i]):
                count+=1
            else:
                count=1
            if(count<=2):
                nums[result] = nums[i]
                result+=1
        return result
