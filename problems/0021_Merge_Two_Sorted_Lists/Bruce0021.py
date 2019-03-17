# 21题，混合2链表并排序
class Solution:
    def mergeTwoLists(self, a, b):
        if not a or b and a.val > b.val:
	        a, b = b, a
	    if a:
	        a.next = self.mergeTwoLists(a.next, b)
	    return a
	
"""
# solution 2 还没看懂啊！20190313
class Solution:
    def mergeTwoLists(self, a, b):
	    if a and b:
		    if a.val > b.val:
			    a, b = b, a
			a.next = self.mergeTwoLists(a.next, b)
		return a or b
		
"""	
	