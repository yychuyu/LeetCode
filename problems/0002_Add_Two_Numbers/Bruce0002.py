# links：https://leetcode.com/problems/add-two-numbers/discuss/1016/Clear-python-code-straight-forward
# 请参考讨论区的内容。

# Runtime: 68 ms, faster than 89.08% of Python online submissions for Add Two Numbers.
# Memory Usage: 10.7 MB, less than 93.79% of Python online submissions for Add Two Numbers.

class Solution:
# @return a ListNode
def addTwoNumbers(self, l1, l2):
    carry = 0
    root = n = ListNode(0)
    while l1 or l2 or carry:
        v1 = v2 = 0
        if l1:
            v1 = l1.val
            l1 = l1.next
        if l2:
            v2 = l2.val
            l2 = l2.next
        carry, val = divmod(v1+v2+carry, 10)
		# divmod函数，把除数和余数运算结果结合起来，
		# 返回一个包含商和余数的元组(a // b, a % b)。
		# 例如：>>>divmod(7, 2)
		# (3, 1)
        n.next = ListNode(val)
        n = n.next
    return root.next
	
	
	#the second solution which works prerry well ,although not as good as the first
	
	"""
	    def addTwoNumbers(self, l1, l2):
        p = dummy = ListNode(-1)
        carry = 0
        while l1 or l2 or carry:
            val = (l1 and l1.val or 0) + (l2 and l2.val or 0) + carry
            carry = val / 10
            p.next = ListNode(val % 10)
            l1 = l1 and l1.next
            l2 = l2 and l2.next
            p = p.next
        return dummy.next
	
    """
	