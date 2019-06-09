# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def __init__(self):
        self.last_right = None
        
    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        if not root:
            return 
        self.flatten(root.right)
        self.flatten(root.left)
        
        root.right = self.last_right
        root.left = None
        self.last_right = root
class Solution:
    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        result = []
        self.dfs(root, result)
        return result
        
    def dfs(self, root, result):
        result.append(root.val)
        if root.left:
            self.dfs(root.left, result)
        if root.right:
            self.dfs(root.right, result)
class Solution:
    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        while root:
            if root.left:
                if not root.right:
                    root.right = root.left
                    root.left = None
                else :
                    cur = root.right
                    root.right = root.left
                    root.left = None
                    now = root.right
                    while now.right:
                        now = now.right
                    now.right = cur
            root = root.right
class Solution:
    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        if not root:
            return 
        self.flatten(root.left)
        self.flatten(root.right)
        right = root.right
        root.right = root.left
        root.left = None
        while root.right:
            root = root.right
        root.right = right