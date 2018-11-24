# Referred to zhuyinghua
class Solution:
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        
        # recursive solution
        # prior: the list has been sorted
        def findNsum(nums, target, N, result, results):
            # Some situation for early termination
            # The count of left element of list is not enough for N
            # N is reduced to 1
            # The target is smaller than min(list)*N
            # The target is larger than max(list)*N
            # Searching process can be terminated in these situations
            if len(nums) < N or N < 2 or target < nums[0]*N or target > nums[-1]*N:
                return
            if N == 2: # two pointers solve sorted 2-sum problem
                l,r = 0,len(nums)-1
                while l < r:
                    s = nums[l] + nums[r]
                    if s == target:
                        results.append(result + [nums[l], nums[r]])
                        l += 1
                        while l < r and nums[l] == nums[l-1]:
                            l += 1 # skip the same integers
                    elif s < target:
                        l += 1
                    else:
                        r -= 1
            else: # recursively reduce N
                for i in range(len(nums)-N+1): # gaurantee that the first integer of the last N integer can be visited
                    if i == 0 or (i > 0 and nums[i-1] != nums[i]): # the current integer is not the same with the last integer
                        findNsum(nums[i+1:], target-nums[i], N-1, result+[nums[i]], results)

        results = []
        findNsum(sorted(nums), target, 4, [], results)
        return results






























