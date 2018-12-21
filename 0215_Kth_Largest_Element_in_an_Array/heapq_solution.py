# use min_heap
import heapq
class Solution:
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        N = len(nums)
        if (N<k or k<=0):
            raise Exception('Invalid input!')
            
        nums = [-num for num in nums] # find the kth biggest from num= find the kth smallest from -num
        heapq.heapify(nums)
        res = float('inf')
        for _ in range(k):
            res = heapq.heappop(nums)
        return -res
        
        
