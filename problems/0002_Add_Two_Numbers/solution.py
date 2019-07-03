# 这道题目主要是,使用链表来表示大数
# 通过遍历两个链表,将对应的位上的数字相加
# 相加的时候,要注意进位的问题
# 同时,应该注意两个链表长度不同的问题
# 最后,还应该检查最后两个数字相加后,是否有进位的问题


class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def addTwoNumbers(self, l1, l2):
        root = ListNode(0)
        node = root
        res = 0
        while l1 or l2:
            x = l1.val if l1 else 0
            y = l2.val if l2 else 0
            s = res + x + y
            node.next = ListNode(s % 10)
            res = s // 10
            if l1 is not None: l1 = l1.next
            if l2 is not None: l2 = l2.next
        if res > 0: node.next = ListNode(1)
        return root.next
