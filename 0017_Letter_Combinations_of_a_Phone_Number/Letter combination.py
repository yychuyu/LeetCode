class Solution:
    def listCombinations(self, list_1, list_2):
        ans = []
        if len(list_1) == 0:
            return list_2
        if len(list_2) == 0:
            return list_1
        for c1 in list_1:
            for c2 in list_2:
                ans.append(c1+c2)
        return ans

    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """      
        ans = []
        nums = {'2':'abc','3':'def','4':'ghi','5':'jkl','6':'mno','7':'pqrs','8':'tuv','9':'wxyz'} 
        for n in digits:
            list_1 = list(nums[n])
            ans = self.listCombinations(ans, list_1)
        return ans
