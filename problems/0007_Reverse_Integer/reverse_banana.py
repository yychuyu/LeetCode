class Solution:
    def reverse(self, x):
        x1 = int(str(abs(x))[::-1])
        if x1 > 2**31:
            return 0
        else:
            if x < 0:
                return x1*-1
            else:
                return x1