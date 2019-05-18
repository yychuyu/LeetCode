# 使用index记录上一次元素去重的位置,如果发现后续的元素和上一次去重位置的元素不同,
# 那么就把当前的元素填入上一次去重位置的下一个元素的位置,
# 这样,两次去重的两个元素之间没有重复的元素
# 同时,index标识的是去重后数组最后一个元素的下表,
# 所以,如果要返回去重数组的长度,返回index+1即可
# 同时,对于边界情况,即数组为空的时候,显然不能返回index+1,
# 此时,需要特殊处理,返回0
class Solution:
	def removeDuplicates(self, nums):
		index = 0
		if not nums:
			return index
		for n in nums:
			if nums[index] != n:
				index += 1
				nums[index] = n
		return index+1
