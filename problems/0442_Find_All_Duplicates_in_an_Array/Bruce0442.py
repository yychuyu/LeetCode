#python3运行成功


####solution one   可行。
class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        output = []
        
        for i in range(len(nums)):
           
            while nums[nums[i]-1] != nums[i]:
                temp = nums[nums[i]-1]
                nums[nums[i]-1] = nums[i]
                nums[i] = temp
                
        for i in range(len(nums)):#注意了，这里的for循环要在上述while跳出来后，进行输出，所以这个for不能跟while同一列！
                if (i+1) != nums[i]:
                    output.append(nums[i])
        return output


####solution two 不可行。时间复杂度超了，就因为Bruce多了一句  k=nums[i]-1
class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        output = []
        
        for i in range(len(nums)):
		    k=nums[i]-1           
            while nums[k] != nums[i]:
                temp = nums[k]
                nums[k] = nums[i]
                nums[i] = temp
                
            for i in range(len(nums)):# 下述都要删除4个space进行对齐。
                if (i+1) != nums[i]:
                    output.append(nums[i])
            return output
			