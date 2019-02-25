# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def addTwoNumbers(self,l1,l2):
        cur1 = l1
        cur2 = l2
        str1 = ''
        str2 = ''
        head = ListNode(-1)
        temp = head
        while(cur1 != None):
            str1 += str(cur1.val)
            cur1 = cur1.next
        while(cur2 != None):
            str2 += str(cur2.val)
            cur2 = cur2.next
        result = eval(str1[::-1]) + eval(str2[::-1])
        for i in str(result)[::-1]:
            temp.next = ListNode(eval(i))
            temp = temp.next
        return head.next

    def addTwoNumbers1(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        head = ListNode(0)
        cur = head
        carry = 0
        while (l1 or l2 or carry!=0):
            if l1:
                carry += l1.val
                l1 = l1.next
            if l2:
                carry += l2.val
                l2 = l2.next
            cur.next = ListNode(carry % 10)
            carry = 0 if carry<10 else 1
            cur=cur.next
        return head.next
    
    def addTwoNumbers2(self,l1,l2):
        p = ListNode(0)
        l3 = p
        overflow = 0

        while l1.next is not None and l2.next is not None:
            temp = l1.val + l2.val + overflow
            l3.val = temp % 10
            overflow = temp // 10
            l1 = l1.next
            l2 = l2.next
            l3.next = ListNode(0)
            l3 = l3.next

        temp = l1.val + l2.val + overflow
        l3.val = temp % 10
        overflow = temp // 10
        l3.next = ListNode(None)  # 先不前移指针，以便最后删除None节点

        if l1.next is not None:  # 相加结束，将l3衔接至尚未结束的链表上
            l3.next = l1.next
        elif l2.next is not None:
            l3.next = l2.next

        if overflow != 0:
            try:
                l3.next.val += overflow  # 考虑无限进位问题 1+99999999...
            except:
                l3.next.val = 0
                l3.next.val += overflow  # 无最高位，手动置0

            while l3.next.val > 9:
                l3.next.val -= 10
                l3 = l3.next
                try:
                    l3.next.val += 1  # 9999 + 1 = 10000的情况,最高位要新建节点
                except:
                    l3.next = ListNode(0)
                    l3.next.val += 1
                    
        if l3.next.val is None:  # 清除val = None的多余节点
            l3.next = None
        return p