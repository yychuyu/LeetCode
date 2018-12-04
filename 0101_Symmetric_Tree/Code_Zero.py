# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        def isSameTree(biTree1, biTree2):
            # 若子树皆为空，则返回True
            if not biTree1 and not biTree2:
                return True
            if biTree1 and biTree2 and biTree1.val == biTree2.val:
                # 递归操作
                leftTree = isSameTree(biTree1.left, biTree2.right)
                rightTree = isSameTree(biTree1.right, biTree2.left)
                return leftTree and rightTree
            else:
                return False
        if not root:
            return True
        else:
            return isSameTree(root.left, root.right)
        
