# !/usr/bin/env python3
# -*- coding:utf-8 -*-

class Solution:
    def findKthLargest(self, nums, k):  # 64ms(快排)
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        return self.find(nums, k-1, 0, len(nums)-1)

    def find(self, nums, k, left, right):
        l = left
        r = right
        mid = nums[(left + right) // 2]
        while left <= right:
            while nums[left] > mid:
                left += 1
            while nums[right] < mid:
                right -= 1
            if left <= right:
                nums[left], nums[right] = nums[right], nums[left]
                left += 1
                right -= 1
        if right >= k and right > l:
            return self.find(nums, k, l, right)
        if left <= k and left < r:
            return self.find(nums, k, left, r)
        return nums[k]

    def findKthLargest1(self, nums, k):    # 56ms(利用库函数)
        return sorted(nums)[-k]