# !/usr/bin/env python3
# -*- coding:utf-8 -*-

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isMirror(self, a, b):  # 52ms(递归)
        if not a and not b:
            return True
        if a and b and a.val == b.val:
            return self.isMirror(a.left, b.right) and self.isMirror(a.right, b.left)
        return False
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if not root:
            return True
        return self.isMirror(root.left, root.right)