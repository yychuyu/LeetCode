# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    """
    这题的难度感觉就是递归的思想解决吧，递归需要一个退出条件，一直判断到没有孩子节点的时候退出，否则再对左孩子和右孩子继续判断
    """
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        def helper(root, mirror):
            if not root and not mirror:
                return True
            if root and mirror and root.val == mirror.val:
                return helper(root.left, mirror.right) and helper(root.right, mirror.left)
            return False
        return helper(root, root)
