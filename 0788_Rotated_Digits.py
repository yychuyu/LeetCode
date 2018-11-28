class Solution:
    def rotatedDigits(self, N):
        """
        :type N: int
        :rtype: int
        """
        out = 0
        str1 = ''
        for i in range(1,N+1):
            str1 = str(i)
            if(str1.count('3') == 0 and str1.count('4') == 0 and str1.count('7') == 0):
                if(str1.count('1') + str1.count('8') + str1.count('0') != len(str1)):
                    out += 1
        return out
    
if __name__ == "__main__":
    solu = Solution()
    print(solu.rotatedDigits(10))