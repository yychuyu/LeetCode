#!/usr/bin/env python  
#-*- coding:utf-8 -*-  
""" 
@file: Convert Sorted List to Binary Search Tree.py 
@time: 2018/12/14
@software: PyCharm  
"""


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def sortedListToBST(self, head):
        """
        :type head: ListNode
        :rtype: TreeNode
        """
        def sortedArrayToBST(nums):
            if not nums:
                return None
            if nums:
                mid = len(nums) // 2
                root = TreeNode(nums[mid])
                root.left = sortedArrayToBST(nums[:mid])
                root.right = sortedArrayToBST(nums[mid+1:])

        if not head:
            return None
        else:
            lst = []
            while head:
                lst.append(head.val)
                head = head.next

        return sortedArrayToBST(lst)
