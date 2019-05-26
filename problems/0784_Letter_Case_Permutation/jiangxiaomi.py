class Solution:
    def letterCasePermutation(self, S: str) -> List[str]:
        result = []
        if len(S) > 0:  #先单独判断第一个字符
            if S[0].isdigit():
                result.append(S[0])
            elif S[0].islower():
                upper_i_0 = S[0].upper()
                result.append(S[0])
                result.append(upper_i_0)
            elif S[0].isupper():
                lower_i_0 = S[0].lower()
                result.append(S[0])
                result.append(lower_i_0)
        for i in S[1:]:  #对字符串进行循环判断，数字直接尾部添加，字母转换后全排列添加
            if i.isdigit():
                for j in range(len(result)):
                    result[j] += i
            elif i.islower():
                upper_i = i.upper()
                for j in range(len(result)):
                    result.append(result[j] + upper_i)
                    result[j] += i
            elif i.isupper():
                lower_i = i.lower()
                for j in range(len(result)):
                    result.append(result[j] + lower_i)
                    result[j] += i
        return result