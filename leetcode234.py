# !/usr/bin/env python3
# -*- coding:utf-8 -*-

# class ListNode:
#     def __init__(self,x):
#	  self.val = x
#	  self.next = None

class Solution:   # 执行用时:140ms
    def isPalindrome(self,head):
	"""
        :type head: ListNode
        :rtype: bool
        """
	s = []
	while head != None:
	    s.append(head.val)
	    head = head.next
	for i in range(len(s)//2):
	    if s[i] != s[len(s)-i-1]:
	        return False
	return True
'''
# 测试
head = ListNode(1)
p1 = ListNode(2)
p2 = ListNode(2)
p3 = ListNode(1)
head.next = p1
p1.next = p2
p2.next =p3
p = Solution()
print(p.isPalindrome(head))
'''
