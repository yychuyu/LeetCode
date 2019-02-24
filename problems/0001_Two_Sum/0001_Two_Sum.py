class Solution:
    def twoSum(self, nums, target):  
        dicNum={}
        numLen=len(nums)
        for i in range(numLen):
            num=target-nums[i]
            if dicNum.get(num)!=None:                   
                return [dicNum[num],i]
            else:
                dicNum[nums[i]]=i