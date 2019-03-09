# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        if head is None:
            return head
        while head is not None and head.val == val:
            head = head.next;
        list_head = head
        pre = head
        while head is not None:
            if head.val == val:
                pre.next = head.next
                head = head.next
            else:
                pre = head
                head = head.next
        return list_head
        
