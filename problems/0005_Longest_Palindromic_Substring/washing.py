class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """

        def palindrome(string):
            if string == string[::-1]:
                return True

        for i in range(len(s), 0, -1):
            for j in range(0, len(s) - i):
                if palindrome(s[j: j + i + 1]):
                    # print(s[j: j + i + 1])
                    return s[j: j + i + 1]
        return s[:1]


# class Solution:
#     def longestPalindrome(self, s: str) -> str:
#         for i, j in [(i, j) for i in range(len(s)) for j in (0, 1)]:
#             while i > -1 and i + j < len(s) and s[i] == s[i + j]: i, j = i - 1, j + 2
#             r = max(locals().get('r', s[i]), s[i + 1:i + j], key=len)
#         return '' if not s else r


if __name__ == '__main__':
    o = Solution()
    print(o.longestPalindrome("kladlkfjlskdjfasdffdsaddff"))
    print(o.longestPalindrome("asdfggfdsa"))
    print(o.longestPalindrome("aasdfghjkllkjhg"))
    print(o.longestPalindrome(""))
    print(o.longestPalindrome("abcd"))
    print(o.longestPalindrome("qwertrewqiii"))
