# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        dummy = jump = ListNode(0)
        dummy.next = l = r = head
        while True :
            count = 0
            while r and count < k:
                r = r.next
                count = count + 1
            if count == k:
                pre , cur = r , l
                for _ in range(k):
                    cur.next , pre , cur = pre , cur , cur.next
                jump.next, jump, l = pre, l, r 
            else: 
                return dummy.next