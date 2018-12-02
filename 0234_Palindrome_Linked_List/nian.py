class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        f=s=head
        isP=[]
        if(head==None or head.next==None):
            return True
        while(f!=None and f.next!=None):
            f=f.next.next
            s=s.next
        while(s!=None):
            isP.append(s.val)
            s=s.next
        while(len(isP)):
            if(isP.pop()!=head.val):
                return False
            head = head.next
        return True
