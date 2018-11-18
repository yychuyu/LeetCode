class Solution(object):
    def sortColors(self, nums):
        l = len(nums)
        i,j = 0,0
        k=l-1
        while(i<=k):
            if(nums[i]==1):
                i+=1
            elif(nums[i]==0):
                nums[i],nums[j] = nums[j],nums[i]
                j+=1
                i+=1
            else:
                nums[i],nums[k] = nums[k],nums[i]
                k-=1
