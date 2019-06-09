class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        line, row = len(word1) + 1, len(word2) + 1
        dp = [[0] * row for _ in range(line)]
        dp[0] = list(range(row))
        for i in range(1, line):
            for j in range(row):
                if j == 0:
                    dp[i][j] = i
                elif word1[i - 1] == word2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1]
                else:
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1],
                                   dp[i - 1][j - 1]) + 1
        return dp[-1][-1]