# 首先,通过中序遍历,把二叉树遍历成一个list
# 其次,从二叉树的根节点开发,把左子节点置为空,
# 右节点置为遍历列表中的元素,即可首先二叉树的展开
# 此处需要注意,在遍历中序遍历的结果列表时,第一个元素是root节点的值,
# 所以,不用取,应该从第二个元素开始

class Solution:
	def flattern(self, root):
		def preRoot(root, res):
			if not root:
				return
			res.append(root.val)
			preRoot(root.left, res)
			preRoot(root.right, res)
		if not root:
			return
		res = []
		preRoot(root, res)
		if root.left:
			root.left = None
		parent = root
		for i in res[1:]:
			parent.right = TreeNone(r)
			parent = parent.right
		return
