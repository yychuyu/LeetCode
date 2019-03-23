# 第二十题

# Solution one in python

# 下述内容有问题。需要更改

class Solution:
    def isValid(self, s):
	    stack = []
		dict = {"]":"[","{":"}",")":"("}
		for char in s:
		    if char in dict.values():
			    stack.append(char)
			elif char in dict.keys():
			    if stack == [] or dict[char] != stack.pop():
				    return False
			else:
			    return False
		return stack == []


# Solution Two in java


		
		