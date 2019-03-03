class Solution(object):
    p = None
    r = None
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if(head==None):
            return head
        self.reverse(head)
        return self.r
        
            
    def reverse(self,n):
        if(n.next==None):
            self.p = ListNode(n.val)
            self.r = self.p
            return
        else:
            self.reverseList(n.next)
            temp = ListNode(n.val)
            self.p.next =temp
            self.p = self.p.next
