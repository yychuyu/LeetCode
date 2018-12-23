# !/usr/bin/env python3
# -*- coding:utf-8 -*-

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sortedListToBST(self, head):  # 168ms
        """
        :type head: ListNode
        :rtype: TreeNode
        """
        nums = []
        while head:
            nums.append(head.val)
            head = head.next
        return self.hhhhh(nums)

    def hhhhh(self, nums):
        if not nums:
            return None
        _len = len(nums)
        mid = _len // 2
        root = TreeNode(nums[mid])
        root.left = self.hhhhh(nums[:mid])
        root.right = self.hhhhh(nums[mid + 1:])
        return root