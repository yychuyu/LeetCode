# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:  
    def addTwoNumbers(self, l1, l2):  
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
       
        if l1 is None:
            return l2
        if l2 is None:
            return l1
        # tmp是暂存（temporal）
        tmp = ListNode(0)  
        # res是重置（reset）
        res = tmp  
        # flag 标示
        flag = 0  
        while l1 or l2:  # l1或l2不为空就持续执行
            tmp_sum = 0  # 链表节点值的和
            if l1:  # 如果l1不为空，把l1的某个节点值的和赋给tmp_sum
                tmp_sum = l1.val  
                l1 = l1.next
            if l2:  # 如果l2不为空，把l2中和l1对应的节点的值加到tmp_sum
                tmp_sum += l2.val
                l2 = l2.next  
            tmp_res = ((tmp_sum + flag) % 10)  
            flag = ((tmp_sum + flag) // 10)  
            res.next = ListNode(tmp_res)
            res = res.next  
            if flag:  # 如果flag不为0，就是对应位置相加后有进位
                res.next = ListNode(1)  
        res = tmp.next  
        del tmp  # 删除tmp变量
        return res  # 返回res链表