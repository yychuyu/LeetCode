# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        
        if not p :
            return not q
        elif q is None or q.val!=p.val:
            return False
        elif p.val == q.val:
            return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)
        '''furthermore
        if not p :
            return not q
        elif not q or q.val!=p.val:
            return False
        return p.val == q.val and  self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)
        
        '''
        
        