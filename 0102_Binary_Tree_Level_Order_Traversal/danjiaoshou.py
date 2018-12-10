# python solution
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
        if root is None:
            return []
        if root.left is None and root.right is None:
            return [[root.val]]
        
        res = []
        current_level = [root]
        res.append([root.val])
        while current_level != []:
            next_level = []
            node_value = []
            for tmp_node in current_level:
                if tmp_node.left is not None:
                    next_level.append(tmp_node.left)
                    node_value.append(tmp_node.left.val)
                if tmp_node.right is not None:
                    next_level.append(tmp_node.right)
                    node_value.append(tmp_node.right.val)
                    
            current_level = next_level # update the current_level
            
            if node_value != []:
                res.append(node_value) # record value of each level
            
        return res
