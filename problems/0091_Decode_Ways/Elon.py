class Solution:
    def numDecodings(self, s: str) -> int:
        dp = [1]
        dp.append(0 if s[0] == '0' else 1)
        for i, num in enumerate(s[1:], 1):
            connect = s[i - 1] + num
            if num == "0":
                if s[i - 1] == '1' or s[i - 1] == '2':
                    dp.append(dp[i - 1])
                else:
                    dp.append(0)
            elif ("11" <= connect <= "26"):
                dp.append(dp[i - 1] + dp[i])
            else:
                dp.append(dp[i])
        return dp[-1]