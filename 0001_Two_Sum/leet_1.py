class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        
        '''for i in range(len(nums)):
            for j in range(i+1,len(nums)):
                if nums[i] + nums[j] ==target:
                    return [i,j]'''
        d={}
        for i in range(len(nums)):
            if target-nums[i] in d:
                return [d[target-nums[i]],i]
            d[nums[i]]=iThis file is added by shichao
