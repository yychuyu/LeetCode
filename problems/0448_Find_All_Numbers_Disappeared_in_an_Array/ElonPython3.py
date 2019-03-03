class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        index = 0
        while(index < len(nums)):
            if nums[index] != index + 1 and nums[index]!= nums[nums[index]-1]:
                nums[nums[index] - 1],nums[index], = nums[index], nums[nums[index]-1]
            else :
                index += 1
        result = []
        for index, num in enumerate(nums):
            if num != index + 1 :
                result.append(index + 1)
        return result