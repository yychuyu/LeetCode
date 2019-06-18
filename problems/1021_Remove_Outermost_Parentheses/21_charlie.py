class Solution:
    def removeOuterParentheses(self, S: str) -> str:
        count = 0
        new_string = ""
        for index in S:
            if index == '(':
                count += 1
                if count > 1:
                    new_string += '('
            else:
                count -= 1
                if count > 0:
                    new_string += ')'
        return new_string
