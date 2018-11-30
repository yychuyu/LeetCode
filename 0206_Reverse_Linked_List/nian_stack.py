class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        l = []
        while(head!=None):
            l.append(head.val)
            head = head.next
        if(len(l)):
            r = ListNode(l.pop())
            p = r
        else:
            return head
        while(len(l)):
            n = ListNode(l.pop())
            p.next = n
            p = p.next
        return r
