'''
  题目：
  给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
  
  说明：
  有效字符串需满足：左括号必须用相同类型的右括号闭合。左括号必须以正确的顺序闭合。
  注意空字符串可被认为是有效字符串。
  
  参考：
  https://blog.csdn.net/qq_17550379/article/details/80723003
'''
class Solution:
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stk = list()
        m = {'(':')','[':']','{':'}'}
        for i in s:
            if i == '(' or i == '[' or i == '{':
                stk.append(i)
            else:
                if len(stk) == 0:
                    return False
                top = stk.pop()
                if m[top] != i:
                    return False
        if len(stk) == 0:
            return True
        
        return False   
