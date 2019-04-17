class Solution:
	def findDiagonalOrder(self, matrix):
		res = []
		if not matrix:
			return res
		m = len(matrix)
		n = len(matrix[0])
		top = True
		i = j = 0
		while i < m and j < n:
			res.append(matrix[i][j])
			if top:
				if j == n - 1:
					i += 1
					top = False
				elif i == 0:
					j += 1
					top = False
				else:
					i -= 1
					j += 1
			else:
				if i == m - 1:
					j += 1
					top = True
				elif j == 0:
					i += 1
					top = True
				else:
					i += 1
					j -= 1
		return res
