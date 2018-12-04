class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        nums.sort()
        res=nums[0]+nums[1]+nums[-1]
        for i in xrange(len(nums)-2):
            l,r=i+1,len(nums)-1
            while l<r:
                diff = nums[i]+nums[l]+nums[r]-target
                if abs(res-target)>abs(diff):
                    res = nums[i]+nums[l]+nums[r]
                if diff==0:
                    return target
                elif diff<0:
                    l+=1
                else :
                    r-=1
        return res
