class Solution:
    def twoSum(self, target, *nums1):
        element_used = []
        nums =list(nums1)
        for i in range(len(nums)-1):
            for j in range(i+1, len(nums)-1):
                if nums[j] + nums[i] == target and nums[i] != nums[j] :
                    if nums[j] in element_used:
                        continue
                    else:
                        element_used.append(nums[j])
                        element_used.append(nums[i])
                        print([i,  j])

judge = Solution()
judge.twoSum(9, 2, 7, 11, 15)   
