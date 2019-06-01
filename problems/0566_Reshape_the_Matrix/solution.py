# 首先,需要对边界的情况做出处理
# 如果重塑后的矩阵的元素数量大于原始矩阵的元素数量,则为异常情况
# 对于正常情况,我们遍历原来的矩阵,
# 并且定义两个数组,一个用来存放新的矩阵,一个用来存放矩阵每行的元素
# 在遍历时,如果行数组的元素数量满足新矩阵对列元素数量的要求
# 那么将该行数组放入新矩阵数组中,然后清空行数组,继续遍历,直至结束
class Solution:
	def matrixReshape(self, nums, r, c):
		if r * c > len(nums) * len(nums[0]):
			return nums
		else:
			res = []
			tmp = []
			for line in nums:
				for value in line:
					tmp.append(value)
					if len(tmp) == c:
						res.append(tmp)
						tmp = []
			return res
