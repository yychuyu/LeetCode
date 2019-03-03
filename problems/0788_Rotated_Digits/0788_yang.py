"""
X is a good number if after rotating each digit individually by 180 degrees,
we get a valid number that is different from X.  Each digit must be rotated -
we cannot choose to leave it alone.

A number is valid if each digit remains a digit after rotation. 0, 1, and 8
rotate to themselves; 2 and 5 rotate to each other; 6 and 9 rotate to each
other, and the rest of the numbers do not rotate to any other number and become
invalid.

Now given a positive number N, how many numbers X from 1 to N are good?
"""


class Solution:
    def rotatedDigits(N):
        """
        :type N: int
        :rtype: int
        """
        s1 = set([0, 1, 8])
        s2 = set([0, 1, 8, 2, 5, 6, 9])
        s = set()
        res = 0
        N = map(int, str(N))

        for i, digit in enumerate(N):
            for j in range(digit):
                if s.issubset(s2) and j in s2:
                    res += 7 ** (len(N) - i - 1)
                if s.issubset(s1) and j in s1:
                    res -= 3 ** (len(N) - i - 1)

            if digit not in s2:
                return res
            s.add(digit)

        return res + (s.issubset(s2) and not s.issubset(s1))
