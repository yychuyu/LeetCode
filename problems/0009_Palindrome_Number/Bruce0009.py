"""
官方提示如下：

1，负数都不是回文数；
2，不能通过将数字转为字符串来判断回文，
   因为使用了额外的空间（即只能使用空间复杂度 O(1) 的方法）；
3，注意整数溢出问题；
4，这个问题有一个比较通用的解法。
"""
# 方法二比较巧妙！！！


# Solution one  设置了一个新的回文数，判断是否会相等。

class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x < 0:
            return False

        tmp = x
        y = 0
        while tmp:
            y = y*10 + tmp%10
            tmp = tmp/10
        return y == x
		
# Solution Two 将各个数字单独比较。
# [注意了，该Solution需要改进，因为python中的求商取余会是float类型，这里需要改进为”整型“]
# Links：https://blog.csdn.net/coder_orz/article/details/51308466 
# 这个方法比较巧妙。

class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x < 0:
            return False

        digits = 1
        while x/digits >= 10:
            digits *= 10

        while digits > 1:
            right = x%10
            left = x/digits
            if left != right:
                return False
            x = (x%digits) / 10
            digits /= 100
        return True

# Solution Two 改进如下：需要转换为整形（int）才能在PyCharm中编译正确，注意咯，这里的digits的变换方式。。
class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x < 0:
            return False

        digits = 1
        while x/digits >= 10:
            digits *= 10

        while digits > 1:
            right = int(x%10)    # 取余，得到一个数字
            left = int(x/digits) # 取商，得到一个数字
            if left != right:
                return False
            x = int((x%digits)) / 10   # 如果上述X的两端数字相等了，就进行下一步循环。
			# 上一行的取余，是去掉了最左端的一个数字；取商，使得最右端的数字到了小数点后的小数部分。
			# 因此此时x的整数部分，相对上一步循环，少了2个数字。
			# 所以下一行的digits要用100去取余后，回到while digits>1的循环中去。
            digits /= 100
        return True

