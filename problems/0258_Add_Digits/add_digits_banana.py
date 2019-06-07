class Solution:
    def addDigits(self, num):
        while(num > 9):
            num = int(num/10) + num % 10
        return num