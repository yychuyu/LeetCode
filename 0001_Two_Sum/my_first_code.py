class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        n = len(nums)

        for x in range(n):
            a = target - nums[x]
            
            if a in nums:
                y = nums.index(a)
                
                if x == y:
                    continue
                else:
                    return x,y
                    break
            else :
                continue
