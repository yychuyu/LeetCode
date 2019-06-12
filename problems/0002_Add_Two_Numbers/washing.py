# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        return_link = ListNode(None)

        def add(val):
            node = ListNode(val)
            if return_link.val != None:
                return_link.val = val
            else:
                cur = return_link
                while cur.next:
                    cur = cur.next
                cur.next = node


        plus = 0
        while l1 and l2:
            add_together = l1.val + l2.val + plus
            ans = add_together % 10
            plus = add_together // 10
            add(ans)
            l1, l2 = l1.next, l2.next

        if l1:
            rest = l1
        else:
            rest = l2
        while rest:
            add_together = rest.val + plus
            ans = add_together % 10
            plus = add_together // 10
            add(ans)
            rest = rest.next
        if plus:
            add(plus)

        return return_link.next