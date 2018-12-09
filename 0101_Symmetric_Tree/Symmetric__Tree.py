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

        def isSameTree(p,q):
            if not p and not q:
                return True  
            if p and q and p.val==q.val:  
                l=isSameTree(p.left,q.right)  
                r=isSameTree(p.right,q.left)  
                return l and r
            else:  
                return False
        if not root:
            return True
        else:
            return isSameTree(root.left,root.right)
