# solution one
class Solution:
	def mergeTwoLists(self, l1, l2):
		if l1 is None:
			return l2
		if l2 is None:
			return l1
		head = l1 if l1.val < l2.val else l2
		nonhead = l2 if l1.val < l2.val else l1
		head.next = self.mergeTwoLists(head.next, nonhead)
		return head

# solution two
class Solution:
	def mergeTwoLists(self, l1, l2):
		if l1 is None:
			return l2
		if l2 is None:
			return l1
		if l1.val < l2.val:
			l1.next = self.mergeTwoLists(l1.next, l2)
			return l1
		else:
			l2.next = self.mergeTwoLists(l1, l2.next)
			return l2

# solution three
class Solution:
	def mergeTwoLists(self, l1, l2):
		if l1 is None:
			return l1
		if l2 is None:
			return l2
		dummy = ListNode(-1)
		cur = dummy
		while l1 is not None and l2 is not None:
			if l1.val < l2.val:
				cur.next = l1
				l1 = l1.next
			else:
				cur.next = l2
				l2 = l2.next
			cur = cur.next
		cur.next = l1 if l1 is not None else l2
		return dummy.next
