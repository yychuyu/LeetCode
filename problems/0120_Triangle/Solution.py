# 为了避免使用额外的存储空间,我们使用三角的最后一行来存储中间计算的结果
# 我们最终目的是求每一行最小元素的和
# 我们先求出最后一行的最小值放在最后一行的第一个元素
# 然后遍历倒数第二行值第一行的所有数组,
# 然后把每一行的最小值加到最后一行的第0个元素之上
# 这样我们就得到三角行的最小路径之和了
class Solution:
	def mininumTotal(self, triangle):
		if not triangle:
			return 0
		n = len(triangle)
		triangle[n-1][0] = min(triangle[n-1])
		for i in range(n-2, -1, -1):
			triangle[n-1][0] += min(triangle[i])
		return triangle[n-1][0]
