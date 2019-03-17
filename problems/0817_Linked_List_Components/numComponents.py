# -*- coding:utf-8 -*-

class Solution:
    def numComponents(self, head: ListNode, G: List[int]) -> int:
        g_set = set(G)
        count = 0
        while head:
            if head.val in g_set and (head.next is None or head.next.val not in g_set):
                count += 1
            head = head.next
        return count
