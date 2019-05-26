# coding:utf8


class Solution:
    def wordBreak(self, s, wordDict: list) -> bool:
        if not s:
            return True

        breakp = [0]
        for i in range(len(s) + 1):
            for j in breakp:
                if s[j:i] in wordDict:
                    breakp.append(i)
                    break
        print(f"breakp: {breakp}")
        return breakp[-1] == len(s)
