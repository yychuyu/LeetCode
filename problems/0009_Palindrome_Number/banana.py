class Solution:
    def isPalindrome(self, x):
        if (x < 0 or (x % 10 == 0 and x != 0)):
            return False

        a = 0
        while (x > a):
            a = a * 10 + x % 10
            x = int(x / 10)
        return int(a / 10) == x or x == a