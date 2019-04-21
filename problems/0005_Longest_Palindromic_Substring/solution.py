class Solution:
	def longestPalindrome(self, s):
		if not s:
			return s
		sl = len(s)
		if not sl:
			return s
		dp = [[False for i in range(sl)] for j in range(sl)]
		max_length = 0
		start = 0
		for i in range(sl -1, -1, -1):
			for j in range(sl - 1, i - 1, -1):
				if i == j:
					dp[i][j] = True
				if j - i == 1:
					dp[i][j] = (s[i] == s[j])
				if j - i >= 2:
					dp[i][j] = (s[i] == s[j]) and (dp[i+1][j-1])
				if dp[i][j] and (j - i + 1 > max_length):
					max_length = j - i + 1
					start = i
		return s[start: start + max_length]
