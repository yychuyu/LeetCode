#
# @lc app=leetcode.cn id=38 lang=python3
#
# [38] 报数
#
# https://leetcode-cn.com/problems/count-and-say/description/
#
# algorithms
# Easy (47.57%)
# Total Accepted:    19.9K
# Total Submissions: 41.6K
# Testcase Example:  '1'
#
# 报数序列是一个整数序列，按照其中的整数的顺序进行报数，得到下一个数。其前五项如下：
# 
# 1.     1
# 2.     11
# 3.     21
# 4.     1211
# 5.     111221
# 
# 
# 1 被读作  "one 1"  ("一个一") , 即 11。
# 11 被读作 "two 1s" ("两个一"）, 即 21。
# 21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。
# 
# 给定一个正整数 n（1 ≤ n ≤ 30），输出报数序列的第 n 项。
# 
# 注意：整数顺序将表示为一个字符串。
# 
# 
# 
# 示例 1:
# 
# 输入: 1
# 输出: "1"
# 
# 
# 示例 2:
# 
# 输入: 4
# 输出: "1211"
# 
# 
#
class Solution:
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        '''
        if n == 1:
            return '1'
        curr_all = '11'
        after_all = ''
        for _ in range(n-2):
            count = 1
            after_all = ''
            for i in range(1, len(curr_all)):
                if curr_all[i] == curr_all[i-1]:
                    count += 1
                else:
                    after_all = after_all + str(count) + curr_all[i-1]
                    count = 1
            after_all = after_all + str(count) + curr_all[i]

            curr_all = after_all

        return curr_all
        '''
        curr_all = '1'
        for _ in range(n-1):
            after_all = ''
            i = 0
            while i < len(curr_all):
                count = 1
                while (i+1)<len(curr_all) and curr_all[i] == curr_all[i+1]:
                    count += 1
                    i += 1
                after_all += str(count) + curr_all[i]
                i += 1

            curr_all = after_all

        return curr_all


sol = Solution()
print(sol.countAndSay(4))





        
