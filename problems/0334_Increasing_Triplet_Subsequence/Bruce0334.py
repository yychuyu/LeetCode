# 334 solution by Bruce


class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        low, mid = 0, -1
        for i in range(len(nums)):
            if nums[i] <= nums[low]:
                low = i
            elif mid == -1 and nums[i] > nums[low]:
                mid = i
            elif nums[i] <= nums[mid]:
                mid = i
            elif mid != -1 and nums[i] > nums[mid]:
                return True
        return False
    
	
	'''
	#####################

def increasingTriplet(nums):
    first = second = float('inf')
    for n in nums:
        if n <= first:
            first = n
        elif n <= second:
            second = n
        else:
            return True
    return False	

####################################3	


class Solution(object):
    def increasingTriplet(self, nums):
        """
        : type nums: List[int]
        : rtype: bool
        """
        low, mid = 0, -1
        for i in range(len(nums)):
            if nums[i] <= nums[low]:
                low = i
            elif mid == -1 and nums[i] > nums[low]:
                mid = i
            elif nums[i] <= nums[mid]:
                mid = i
            elif mid != -1 and nums[i] > nums[mid]:
                return True
        return False
	'''