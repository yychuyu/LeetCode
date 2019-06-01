# 主要采用二叉树中序遍历的方法来解决
# 根据二叉搜索树的定义
# 在中序遍历的时候，每次递归调用方法，会有三个参数
# 当前节点，本次遍历的上限，本次遍历的下限
# 如果是root节点，那么当前的上限和下限分别是正无穷和负无穷
# 如果是非root节点，若当前节点的值不在上限和下限之间，
# 那么就不是二叉搜索树,
# 若在上限和下限之间，则继续遍历左子树和右子树
# 此时，左子树的上限是当前节点的值，下限不变
# 右子树的下限是当前节点的值，上限不变
class Solution:
	def isValidBST(self, root):
		def check(node, lower, upper):
			if node.val > lower and node.val < upper:
				return check(node.left, lower, node.val) and check(node.right, node.val, upper)
			else:
				return False
		return check(root, float("-inf"), float("-inf"))
