class Solution(object):
    def letterCombinations(self, digits):
        
        phoneMap = { '2': 'abc', '3': 'def', '4': 'ghi', '5': 'jkl', '6': 'mno', '7' : 'pqrs', '8': 'tuv', '9':'wxyz'}
        number = str(digits)

        if number == "":
        	return []

        result = ['']
        for char in number:
        	values = phoneMap[char]
        	new_result = []
        	for prefix in result:
        		currElement = prefix
        		for value in values:
        			new_result.append(currElement+value)

        	result = new_result
        	# result = [prefix+value for prefix in result for value in values]
        return result

print Solution().letterCombinations("23")