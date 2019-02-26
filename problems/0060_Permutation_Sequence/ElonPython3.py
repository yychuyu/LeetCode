class Solution:
    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        return self.findPemutation(n, k)
    
    def findPemutation(self, n, k):
        
        nummap = { 1: 0, 2: 1, 3: 2, 4: 6, 5: 24, 6: 120, 7: 720, 8: 5040, 9: 40320}
        nums = list(map(str,list(range(1,n+1))))
        res = ""
        while k:
            if n == 1:
                return res + nums.pop()
            mod = k % nummap[n]
            quotient = k // nummap[n]
            if mod == 0:
                res += nums.pop(quotient-1)
                return res + "".join(sorted(nums,reverse=True))
            elif mod == 1:
                res += nums.pop(quotient)
                return res + "".join(sorted(nums))
            else:
                res += nums.pop(quotient)
                k = mod
                n = n-1