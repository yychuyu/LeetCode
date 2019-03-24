# 第26题

# 还没怎么仔细看啊！！！

class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        num_count = 0
        if not nums:
            return num_count
        
        current_num_and_index = None, -1
		
		"""
		这一句可以改成类似的
		current_num = None
        current_idx = -1		
		"""
		
        for num in nums:
            if num != current_num_and_index[0]:
                new_index = current_num_and_index[1]+1
                nums[new_index] = num
                current_num_and_index = num, new_index
                num_count += 1
        return num_count

		
"""
Links: https://leetcode.com/problems/remove-duplicates-from-sorted-array/discuss/242102/Simple-Python-Solution-44ms-(99.91)

这个还没ac。。。需要稍微修改一下

    def removeDuplicates(self, nums):
        unique_count = 0
        if not nums:
            return unique_count
        current_num = None
        current_idx = -1
        for x in nums:
            if x != current_num:
                new_idx = current_idx + 1
                nums[new_idx] = x
                current_num = x 
                current_idx = new_idx
                unique_count += 1
        nums = nums[0:unique_count]
        return unique_count


"""		
		