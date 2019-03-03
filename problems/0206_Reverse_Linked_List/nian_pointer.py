class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        pre = None
        while(head):
            temp = head.next  # 保存下一个节点
            head.next = pre   # 当前节点指向前一个节点(实现反转) 
            pre = head        # 前一个节点设为当前节点
            head = temp       # 当前节点后移
        return pre
