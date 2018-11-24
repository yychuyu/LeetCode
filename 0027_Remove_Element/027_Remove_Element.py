class Solution(object):
    def removeElement(self, nums, val):
        l = len(nums)
        result = l
        j=0
        for i in range(l):
            if(val != nums[i]):
                temp = nums[i]
                nums[i] = nums[j]
                nums[j] = temp
                j+=1
            else:
                result-=1
        return result
