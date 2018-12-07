class Solution:
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        res = []
        for i in range(len(nums)):
            if i > 0 and nums[i]==nums[i-1]:
                continue
            l , r = i+1 , len(nums)-1
            while l < r :
                summ=nums[i] + nums[l] + nums[r]
                if summ < 0:
                    l = l + 1
                elif summ > 0:
                    r = r - 1
                else:
                    res.append([nums[i] , nums[l], nums[r]])
                    while l < r and nums[l]==nums[l + 1]:
                        l = l + 1
                    while l < r and nums[r]==nums[r - 1]:
                        r = r - 1
                    l = l + 1
                    r = r - 1
        return res
