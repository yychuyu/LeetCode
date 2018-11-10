# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isSubtree(self, s, t):
        if(s==None):
            return False
        if(self.isSametree(s,t)):
            return True
        else:
            return(self.isSubtree(s.left,t) or self.isSubtree(s.right,t))
                
    def isSametree(self,s,t):
        if(not s and not t):
            return True
        elif(not s or not t):
            return False
        elif(s.val!=t.val):
            return False
        else:
            return self.isSametree(s.left,t.left) and self.isSametree(s.right,t.right)
