# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        dummy = ListNode(-1)
        dummy.next = head
        now = dummy 
        while now.next != None:
            if now.next.val != val:
                now = now.next
            else :
                now.next = now.next.next
                
        return dummy.next