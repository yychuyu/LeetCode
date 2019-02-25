# solution by zhazha
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def detectCycle(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        
        # empty list
        if head == None:
            return None
        
        # special case: list with one node and cycle next
        if head == head.next:
            return head

        # judging having cycle in the list
        fast_node = head.next
        slow_node = head
        while(fast_node != slow_node):
            if (fast_node is None):
                return None
            
            fast_node = fast_node.next
            slow_node = slow_node.next
            if (fast_node is None or slow_node is None):
                return None
            
            fast_node = fast_node.next
            if fast_node == slow_node:
                judge_cycle = True
        
        # find the length of cycle list
        steps = 1
        cycle_node = fast_node.next
        while(cycle_node != fast_node):
            steps += 1
            cycle_node = cycle_node.next
        cycle_len = steps
            
        # find the entrance of cycle
        fast_node = head
        slow_node = None
        steps = 0
        while(fast_node != slow_node):
            steps += 1
            fast_node = fast_node.next
            if slow_node is not None:
                slow_node = slow_node.next
                
            if steps == cycle_len:
                slow_node = head
        return fast_node
