# recursive python solution
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def countNodes(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """

        if root is None:
            return 0
        elif (root.left is None and root.right is None): # leaf node
            return 1

        # recursive solution
        current = root

        left_child = current.left
        left_num = Solution.countNodes(self, left_child)
        right_child = current.right
        right_num = Solution.countNodes(self, right_child)
        return left_num + right_num + 1 # remember to contain the current_node itself!


