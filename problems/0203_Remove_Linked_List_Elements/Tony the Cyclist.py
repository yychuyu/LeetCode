# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeElements(self, head, val):
        """
        :type head: ListNode
        :type val: int
        :rtype: ListNode
        """
        if head == None:
            return head
        p = head
        pre = None
        while p:
            if head.val == val:
                #p = head.next
                pre = p
                head = head.next
            elif p.val == val:
                pre.next = p.next
            else:
                pre = p
            if p:
                p = p.next
        return head
