class Solution(object):
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        results=[]
        self.FindNSum(sorted(nums),target,[],4,results)
        return results
        
    def FindNSum(self,nums,target,vessel,N,results):
        if len(nums)<N or N<2 or target<nums[0]*N or target > nums[-1]*N:
            return
        if N == 2:
            l,r=0,len(nums)-1
            while l < r:
                s = nums[l]+nums[r]
                if s == target:
                    results.append(vessel+[nums[l],nums[r]])
                    l+=1
                    while l< r and nums[l]==nums[l-1]:
                        l+=1
                elif s < target:
                    l+=1
                else : r-=1 
        else :
            for i in range(len(nums)-N+1):
                if i == 0 or (i>0 and nums[i-1]!=nums[i]):
                    self.FindNSum(nums[i+1:],target-nums[i],vessel+[nums[i]],N-1,results)
