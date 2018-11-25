# !/usr/bin/env python3
# -*- coding:utf-8 -*-

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:        # 60ms
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if k == 0 or head == None:
            return head
        dummy = ListNode(0)
        dummy.next = head
        p = dummy
        count = 0
        while p.next:
            p = p.next
            count += 1
        realstep = count - k % count
        p.next = head    # 将尾节点指向头节点，形成环形链表
        for i in range(realstep):
            p = p.next
        head = p.next
        p.next = None
        return head