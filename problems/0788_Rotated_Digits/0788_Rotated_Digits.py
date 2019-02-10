class Solution:
    def rotatedDigits(self, N):
        """
        :type N: int
        :rtype: int
        """
        res = 0
        for num in range(N + 1):
            string_num = str(num)
            if "3" in string_num or "4" in string_num or "7" in string_num:
                continue
            elif "2" in string_num or "5" in string_num or "6" in string_num or "9" in string_num:
                res += 1
        return res
