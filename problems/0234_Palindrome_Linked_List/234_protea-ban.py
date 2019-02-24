"""
234. Palindrome Linked List
 By protea-ban
 """
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        fast = slow = head
        # 找到中间节点
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
        # 翻转后半部分
        prev = None
        while slow:
            tmp = slow.next
            slow.next = prev
            prev = slow
            slow = tmp
        # 比较前后两部分
        while prev: # while prev and head:
            if prev.val != head.val:
                return False
            prev = prev.next
            head = head.next
        return True