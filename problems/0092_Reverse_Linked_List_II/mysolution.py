# -*- coding: utf-8 -*-
"""
Created on Sun Nov 11 17:33:29 2018

@author: zhazha
"""

class Solution:
    def reverseBetween(self, head, m, n):
        """
        :type head: ListNode
        :type m: int
        :type n: int
        :rtype: ListNode
        """
        assert (head is not None), \
            "List is empty!"
        assert (m>=1 and m<=n), \
            "Invalid position!"
        
        # actually no reversed, return original list
        if m == n:
            return head
        
        current_node = head
        
        # m=1, the first node will be reversed,
        # and the current node will be the current first node
        if m == 1:
            first_reversed_node = current_node
            for i in range(1,n+1):
                next_node = current_node.next

                # current node with idx i
                if i > m and i <= n:
                    first_reversed_node.next = current_node.next
                    current_node.next = head
                    head = current_node
                
                current_node = next_node
                
            return head
        
        # m>1
        for i in range(1,n+1):
            next_node = current_node.next
            if i == m-1: # the next node is on the first reversed position
                prior_node = current_node
            
            if i== m:
                first_reversed_node = current_node
                
            # current node with idx i
            if i > m and i <= n:
                current_first_reversed_node = prior_node.next
                prior_node.next = current_node
                first_reversed_node.next = current_node.next
                current_node.next = current_first_reversed_node                           
            current_node = next_node
            
        return head