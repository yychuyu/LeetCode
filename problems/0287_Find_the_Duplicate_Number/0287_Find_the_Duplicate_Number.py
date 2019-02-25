class Solution(object):
    def findDuplicate(self, nums):
        s = nums[nums[0]]
        f = nums[nums[s]]
        while(s!=f):
            s = nums[s]
            f = nums[nums[f]]
        s = 0
        while(s!=f):
            s = nums[s]
            f = nums[f]
        return s
