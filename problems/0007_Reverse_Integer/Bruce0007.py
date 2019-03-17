class Solution(object):
    def reverse(self, x):
	    x = int(str(x)[::-1]) if x >= 0 else -int(str(x)[::-1])
		return x if x < 2147483648 and x >= -2147483648 else 0
		
# 正确。		
class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        x = int(str(x)[::-1]) if x >= 0 else - int(str(-x)[::-1])
		# 这里的[::-1]是逆序输出的意思。
        return x if x < 2147483648 and x >= -2147483648 else 0		
		
		"""
		2147483646与2147483648之间的自然数，也是欧拉在1772年所发现的一个梅森素数，它等于2^31-1，是32位操作系统中最大的符号型整型常量
		"""
	