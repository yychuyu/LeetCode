class Solution(object):
    def coinChange(self, coins, amount):
        if not coins:
        	return 0

        dp = [float('inf') for _ in range(amount+1)]
        dp[0] = 0

        for val in range(1, amount+1):
        	for coin in coins:
        		if coin <= val:
        			dp[val] = min(dp[val-coin]+1, dp[val])
        return dp[amount] if dp[amount] != float('inf') else -1