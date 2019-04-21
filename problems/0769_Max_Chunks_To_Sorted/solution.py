class Solution:
	def maxChunksToSorted(self, arr):
		max_index = 0
		result = 0
		for i, a in enumerate(arr):
			if a > max_index:
				max_index = a
			if max_index == i:
				result += 1
		return result
