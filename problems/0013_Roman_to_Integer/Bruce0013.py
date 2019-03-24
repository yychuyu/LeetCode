 # 13. Roman to Integer
 
 # 这个比较好懂。思路如下：
 # 1. 将出现的单个的罗马字符用来相加。
 # 2. 将出现类似于”IV“的字符，本来表示的是4，
 #    但是上一步我们已经1+5 = 6 了，所以一旦出现过IV，
 #    则需要再减去2.
 # 3. 整体思路汇报完毕。（第二步，用到了python的字典的概念）
 
 # 不过需要提前考虑好IV表示的是数字4,
 
 
# LeetCode中用python3运行才能成功。

class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        add_map = {
            'I': 1,
            'V': 5,
            'X': 10,
            'L': 50,
            'C': 100,
            'D': 500,
            'M': 1000
        }
        sub_map = {
            'IV': 2,
            'IX': 2,
            'XL': 20,
            'XC': 20,
            'CD': 200,
            'CM': 200
        }

        sum = 0
        for c in s:
            sum += add_map[c]
        # for k in sub_map.keys():
        for k in sub_map:  # python查看键值不需要keys()
            if k in s: sum -= sub_map[k]

        return sum


a = Solution()
print(a.romanToInt("IV"))


 
 