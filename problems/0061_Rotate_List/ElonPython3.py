# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if not head :
            return head
        
        dummy = head
        lenth = 0
        
        while dummy:
            lenth = lenth+1
            dummy = dummy.next
            
        k = k % lenth 
        
        if k > 0 :
            lenth = lenth - (k % lenth)
            start = dummy = head
            for _ in range(lenth - 1):
                dummy = dummy.next
            tail = dummy
            head = dummy.next
            while dummy.next:
                dummy = dummy.next
            dummy.next = start
            tail.next = None
        return head
    
