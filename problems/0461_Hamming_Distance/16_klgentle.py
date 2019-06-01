class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        """
        解题思路：先将字符转为二进制，然后将较短的字符左边补0,使两个字符长度相等，然后统计两个字符的差异。
        """
        # swap, make sure x <= y
        if x > y:
            x, y = y, x

        # transfer x, y from int to binary string
        stry = format(y, "b")
        # add 0 in the head of short string strx
        strx = format(x, "b").rjust(len(stry), "0")

        ret = 0
        for i in range(0, len(stry)):
            if stry[i] != strx[i]:
                ret += 1
        return ret
