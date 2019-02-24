#!/usr/bin/python3  
# -*- coding: utf-8 -*-
# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        flag = True
        lst = []
        cursor = head
        while(cursor != None):
            lst.append(cursor.val)
            cursor = cursor.next
        for x,y in zip(lst,lst[::-1]):
            if x != y:
                flag = False
        return flag

    def isPalindrome1(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        res = []
        while head:
            res.append(head.val)
            head = head.next
        for i in range(int(len(res)/2)):
            if res[i] != res[-i-1]:
                return False
        return True
    
    def isPalindrome2(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        stack = []
        while head:
            stack.append(head.val)
            head = head.next
        return stack == stack[::-1] 