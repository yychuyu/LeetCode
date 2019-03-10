# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def numComponents(self, head: ListNode, G: List[int]) -> int:
        Gset = set(G)
        result = 0
        started = False
        while head != None:
            if head.val in Gset:
                if not started:
                    started = True
                head = head.next
            else:
                if started:
                    result += 1
                    started = False
                head = head.next
        if started:
            result += 1
        return result    
        
    def smarter(self, head: ListNode, G: List[int]) -> int:
        Gset = set(G)
        result = 0
        while head != None:
            if head.val in Gset and (head.next == None or head.next not in Gset):
                result += 1
            head = head.next
        return result