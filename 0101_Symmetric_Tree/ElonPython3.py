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
        return self.isSymmetriTree2(root)
        
        
    def isSymmetriTree2(self, root):
        if root is None:
            return True
        vessel = [(root.left, root.right)]
        while vessel:
            pair = vessel.pop()
            if pair[0] is None and pair[1] is None:
                continue
            if pair[0] is None or pair[1] is None:
                return False
            if pair[0].val != pair[1].val:
                return False
            if pair[0].val == pair[1].val:
                vessel.append((pair[0].left, pair[1].right))
                vessel.append((pair[0].right, pair[1].left))
        return True
        
        
    def isSymmetriTree1(self, root):
        if root is None:
            return True
        return self.isMirror(root.left, root.right)
    
    
    def isMirror(self,left,right):
        if left is None and right is None:
            return True
        if left is None or right is None:
            return False
        if left.val != right.val:
            return False
        return self.isMirror(left.right,right.left) and self.isMirror(left.left,right.right)
