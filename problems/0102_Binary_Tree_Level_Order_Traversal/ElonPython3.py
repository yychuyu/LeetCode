# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if root is None :
            return []
        return self.generateLeverOrderTree(root)
    
    def generateLeverOrderTree(self, root):
        ans=[]
        level=[root]
        while root and level:
            ans.append([node.val for node in level])
            LRpair=[(node.left, node.right) for node in level]
            level=[node for LR in LRpair for node in LR if node]
        return ans
    
    def generateLeverOrderTree1(self, root):
        stack = [root]
        vessel = []
        res = []
        while stack:
            length = len(stack)
            for i in range(length):
                vessel.append(stack[i].val)
                if stack[i].left :
                    stack.append(stack[i].left)
                if stack[i].right:
                    stack.append(stack[i].right)
            stack = stack[length:]
            res.append(vessel[:])
            vessel = []
        return res
        
                
