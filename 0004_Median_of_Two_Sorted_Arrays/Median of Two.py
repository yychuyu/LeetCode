class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        nums = nums1 + nums2
        nums.sort()
        length = len(nums)
        medium = length//2
        if length%2 == 1:
            return nums[medium]
        else:
            return (nums[medium-1] + nums[medium])/2
