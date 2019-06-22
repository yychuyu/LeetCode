class Solution(object):
    """
    注意进位是向右进位，以及注意3位数加上3位数为4位数的情况
    """
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        head = ListNode(0)
        new_list = head
        
        flag = 0
        while l1 != None or l2 != None:
            n1 = l1.val if l1 else 0
            n2 = l2.val if l2 else 0
            num = n1 + n2 + flag
            if num >= 10:
                head.next = ListNode(num-10)
                flag = 1
            else:
                head.next = ListNode(num)
                flag = 0
            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None
            head = head.next
        
        if flag == 1:
            head.next = ListNode(1)
        return new_list.next