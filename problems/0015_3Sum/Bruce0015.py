# coding=utf-8
# use python2.7

class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = []
        """
        nums.sort()  -2， -1， 0 ，1 
		
		print(i,i-1,nums[i], nums[i-1],nums)
		(2, 1, -1, -1, [-4, -1, -1, 0, 1, 2])	
		总共有6个元素，i为2，
		 """
        for i in xrange(0, len(nums)):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            target = 0 - nums[i]  # 此时target 为 -1
            start, end = i + 1, len(nums) - 1 # 此时start 为3，end为5
            while start < end:
                if nums[start] + nums[end] > target:  
				# 0 + 1 > -1 成立，然后end 减一为 4. 
                # 再到while判断start和end的大小。
				# 第二次进while，3 < 4 仍满足。0 + 1 仍大于1.
                    end -= 1  
                elif nums[start] + nums[end] < target:
                    start += 1
                else:
                    res.append((nums[i], nums[start], nums[end]))
                    end -= 1
                    start += 1
                    while start < end and nums[end] == nums[end + 1]:
                        end -= 1
                    while start < end and nums[start] == nums[start - 1]:
                        start += 1
        return res
		# 请注意这里return res的缩进。若在while内，则会是输出为空
    