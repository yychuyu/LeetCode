# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        cursor = head
        lst = []
        if head == None:
            return head
        while(cursor.next != None):
            lst.append(cursor.val)
            cursor = cursor.next
        # 让head指向最后一个元素
        print(cursor.val)
        print(lst)
        head = cursor
        while(lst):
            tmp = lst.pop()
            cursor.next = ListNode(tmp)
            cursor = cursor.next
        return head

    def reverseList1(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        prev = None
        p = head
        while p != None:
            next = p.next
            p.next = prev
            prev = p
            p = next
        return prev
    
    def reverseList2(self,head):
        pre = cur = None
        while head:
            cur = head
            head = head.next
            cur.next = pre
            pre = cur
        return cur
    
    def reverseList3(self,head):
        cur , prev = head, None
        while cur:
            cur.next, prev, cur = prev, cur, cur.next
        return prev
    
    def reverseList4(self,head):
        # #迭代  方式
        # if head == None:
        #     return None
        # result = None
        # while head:
        #     tmp = ListNode(head.val)
        #     head= head.next
        #     if result == None:
        #         result = tmp
        #     else:
        #         tmp.next = result
        #         result= tmp
        # return result
        self.result=None
        self.bfs(None,head)
        return self.result
    def bfs(self,result,head):
        '''result是保存反转数组的最后一个节点
        '''
        if head == None:
            # print('end')
            self.result = result
            return 
        tmp = ListNode(head.val)
        if result == None:
            # print(head.val,'diyige')
            result= tmp
        else:
            # print(head.val,'not first')
            tmp.next = result
            result = tmp
         
        self.bfs(result,head.next)