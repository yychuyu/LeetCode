class Solution:
	def isValid(self, s):
		if not s:
			return True
		stack = []
		for c in s:
			if (c == '(') or (c == '{') or (c == ']'):
				stack.append(c)
			else:
				if not stack:
					return False
				top = stack.pop()
				if top == '(' and c != ')':
					return False
				if top == '{' and c != '}':
					return False
				if top == '[' and c != ']':
					return False
		return not stack
