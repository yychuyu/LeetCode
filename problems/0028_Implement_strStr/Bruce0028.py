# 第28题  一长一短字符串匹配
# in c++ / python


# 这个比较简洁：https://blog.csdn.net/lilong_dream/article/details/23655843
# 也讲了C++方法
# ac不通过
class Solution:
    # @param haystack, a string
    # @param needle, a string
    # @return a string or None
    def strStr(self, haystack, needle):
        if not needle:
            return haystack
        
        len1 = len(haystack)
        len2 = len(needle)
        if len1 < len2:
            return None
        
        for i in range(len1 - len2 + 1):
            j = 0
            k = i
            while j < len2 and needle[j] == haystack[k]:
                j += 1
                k += 1
            
            if j == len2:
                return haystack[i:]
        
        return None

# 将上式子稍微改动，还是失败了。。。
class Solution:
    # @param haystack, a string
    # @param needle, a string
    # @return a string or None
    def strStr(self, haystack, needle):
        if not needle:
            return haystack
        
        len1 = len(haystack)
        len2 = len(needle)
        if len1 < len2:
            return -1
        
        for i in range(len1 - len2 + 1):
            j = 0
            k = i
            while j < len2 and needle[j] == haystack[k]:
                j += 1
                k += 1
            
            if j == len2:
                # return haystack[i:]
                return i
        
        # return None
        return -1


# 这个方法还没看懂！！！
# 然后也没有ac

#https://leetcode.com/problems/implement-strstr/discuss/12883/KMP-in-C%2B%2B-explanation-included 
def strStr(self, S, T):
    if not T:
	    return 0
	
	b = [0]*(len(T) + 1)
	i, j = 0, -1
	b[i] = j
	
	# prepare roll-back table
	while i < len(T):
	    # roll-back
		while j >= 0 and T[i] != T[j]: 
		    j = b[j]
			
		i, j = i + 1, j + 1
		b[i] = j 
	
	i = j = 0
	while i < len(S):
	    # roll-back
		while j >= 0 and T[j] != S[i]: 
		    j = b[j]
		i, j = i + 1, j + 1
		if j == len(T):
		    return i - len(T)
		
		return -1
		    
	

