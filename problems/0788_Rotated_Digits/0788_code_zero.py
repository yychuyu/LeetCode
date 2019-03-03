class Solution:
    """
    X is a good number if after rotating each digit individually by 180 degrees, we get a valid number that is different from X.  
    Each digit must be rotated - we cannot choose to leave it alone.

A number is valid if each digit remains a digit after rotation. 0, 1, and 8 rotate to themselves; 2 and 5 rotate to each other; 
6 and 9 rotate to each other, and the rest of the numbers do not rotate to any other number and become invalid.
Exam:
Input: 10
Output: 4
    """
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
