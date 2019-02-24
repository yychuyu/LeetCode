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
        if root is None:
            return True
        return self.isSymmetricCore(root.left, root.right)
    
    def isSymmetricCore(self, lRoot, rRoot):
        if lRoot == None and rRoot == None:
            return True
        if lRoot == None or rRoot == None:
            return False
        
        return (lRoot.val == rRoot.val) \
            and self.isSymmetricCore(lRoot.right, rRoot.left) \
            and self.isSymmetricCore(lRoot.left, rRoot.right)
