class Solution:
	    def isUgly(self, num: int) -> bool:
		        if num > 0:
		               while num % 2 == 0:
		                   num /= 2
		               while num % 3 == 0:
		                   num /= 3
		               while num % 5 == 0:
		                   num /= 5
		           else:
		               return False
		           
		           return num == 1
