class Solution:
    def rotatedDigits(self, N):
        """
        :type N: int
        :rtype: int
        """
        count = 0
        goodNumbers = [2, 5, 6, 9]
        commonNumbers = [0, 1, 8]
        numbers = goodNumbers + commonNumbers
        for i in range(1, N + 1):
            s = str(i)
            
            isValidNumberAfterRotating = True
            for c in s:
                if int (c) not in numbers:
                    isValidNumberAfterRotating = False
                    break
        
            if isValidNumberAfterRotating:
                for c in s:
                    if int(c) in goodNumbers:
                        count += 1
                        break
        return count
