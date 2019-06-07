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

# 之所以,需要对空数组做特殊处理,是因为数组为空,和数组只有一个元素的时候
# index的值是一样的都是0,那么返回值为index+1即为1,这样是无法区分这两种情况的
# 所以,有一个新的改进方法,把index初始值改为-1,这样数组为空和数组只有一个元素
# 时,两者的index值就不一样了
class Solution:
	def removeDuplicates(self, nums):
		index = -1
		for n in nums:
			if index < 0 or n != nums[index]:
				index += 1
				nums[index] = n
		return index + 1
