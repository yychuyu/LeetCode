class Solution:
	def inOrder(self, root, res):
		if root is None:
			return
		self.inOrder(root.left, res)
		res.append(root.val)
		self.inOrder(root.right, res)
	def minDiffInBST(self, root):
		if root is None:
			return 0
		else:
			res = []
			self.inOrder(root, res)
			if len(res) == 1:
				return res[0]
			min_val = res[1] - res[0]
			for i in range(2, len(res)):
				if res[i] - res[i-1] < min_val:
					min_val = res[i] - res[i-1]
			return min_val
