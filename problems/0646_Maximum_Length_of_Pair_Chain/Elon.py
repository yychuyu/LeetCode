class Solution:
    def findLongestChain(self, pairs: List[List[int]]) -> int:
        cur, result = float('-inf'), 0
        for x, y in sorted(pairs, key = lambda x : x[1]):
            if cur < x:
                cur = y
                result += 1
        return result