class Solution:
    def letterCasePermutation(self, S: str) -> List[str]:
        result = ['']
        for c in S:
            if c.isalpha():
                result = [prefix + char for prefix in result for char in [c.lower(),c.upper()]]
            else:
                result = [prefix + c for prefix in result]
        return result
                