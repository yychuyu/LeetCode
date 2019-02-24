class Solution:
    def rotatedDigits(self, N):
        """
        :type N: int
        :rtype: int
        """
        badSet = {'3','4','7'}
        goodSet = {'2','5','6','9'}
        count = 0
        for i in range(N + 1):
            numSet = set(str(i))
            if badSet & numSet:
                continue
            elif goodSet & numSet:
                count += 1
        return count
