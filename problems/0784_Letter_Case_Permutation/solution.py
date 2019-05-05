class Solution:
	def letterCasePermutation(self, S):
		res = []
		l = len(S)
		if l == 0:
			return [""]
		def dfs(start, temp):
			if start >= l or len(temp) == l:
				res.append(temp)
				return
			if S[start].isdigit():
				dfs(start + 1, temp + S[start])
			elif S[start].islower():
				dfs(start + 1, temp + S[start])
				dfs(start + 1, temp + S[start].upper())
			elif S[start].isupper():
				dfs(start + 1, temp + S[start])
				dfs(start + 1, temp + S[start].lower())
		dfs(0, "")
		return res
