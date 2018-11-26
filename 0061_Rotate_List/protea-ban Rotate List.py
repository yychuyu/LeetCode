# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if head == None or k == 0:
            return head

        # 当前指针
        cur = head
        size = 1
        # 循环链表，获取链表长度
        while cur.next:
            size += 1
            cur = cur.next

        # 尾指针
        tail = cur

        # 旋转链表，获取真正要移动的次数
        k = k % size

        p = self.findKth(head, k)

        tail.next = head
        head = p.next
        p.next = None

        return head

    def findKth(self, head, k):
        # dummy为尾指针
        dummy = ListNode(-1)
        dummy.next = head
        p = dummy
        q = dummy

        # 代表尾指针的q后移k位
        for i in range(k):
            q = q.next

        # p是头指针的前一个节点
        while q.next:
            p = p.next
            q = q.next

        return p


