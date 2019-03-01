#!/usr/bin/env python  
#-*- coding:utf-8 -*-  
""" 
@file: Kth Largest Element in an Array.py 
@time: 2018/12/14
@software: PyCharm  
"""


class Solution:
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        nums = sorted(nums, reverse=True)
        # print(nums[k-1])
        return nums[k-1]


if __name__ == '__main__':
    so = Solution()
    nums = [3,2,3,1,2,4,5,5,6]
    k = 4

    # nums = [3,2,1,5,6,4]
    # k = 2

    so.findKthLargest(nums, k)
