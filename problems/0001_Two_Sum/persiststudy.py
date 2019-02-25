'''
Given an array of integers, return indices of the two numbers 
such that they add up to a specific target.

You may assume that each input would have exactly one solution, 
and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
'''

# Time:  O(n)
# Space: O(n)

# Given an array of integers, return indices of the two numbers
# such that they add up to a specific target.
#
# You may assume that each input would have exactly one solution.
#
# Example:
# Given nums = [2, 7, 11, 15], target = 9,
#
# Because nums[0] + nums[1] = 2 + 7 = 9,
# return [0, 1].


class Solution(object):
    def twoSum(self, nums, target):
        '''
        :param nums: list[int]
        :param target: int
        :return: list[int]
        '''
        lookup = {}
        for i, num in enumerate(nums):
            if target - num in lookup:
                return [lookup[target - num], i]
            lookup[num] = i
        return []

class Solution1(object):
    def twoSum(self, nums, target):
        '''
        :param nums: list[int]
        :param target: int
        :return: list[int]
        '''
        for i in range(len(nums)-1, 0, -1):
            if target - nums[i] in nums[:i]:
                return [nums.index(target - nums[i]), i]


mylist = [ 7, 11, 15, 2]
mytarget = 9

if __name__ == '__main__':
    if len(Solution().twoSum(mylist, mytarget)) == 2:
        print Solution().twoSum(mylist, mytarget)
    else:
        print 'There are no two elements to be found satisfied the condition in the list '



