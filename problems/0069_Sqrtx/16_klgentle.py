class Solution:
    """
    解法：二分搜索
    首先确定范围：对于一个非负数 x，它的平方根不会大于 x/2+1。
    因此我们只需要查找，0 到 x/2 +1,之间的数。
    利用二分的方法查找中间的数，看中间数与目标的距离，不断二分调整范围。
    """

    def mySqrt(self, x: int) -> int:
        l = 0
        # 对于一个非负数 x，它的平方根不会大于 x/2+1
        r = x // 2 + 1
        while l <= r:
            mid = (r + l) // 2
            squ = mid ** 2

            if squ < x:
                l = mid + 1
            elif squ == x:
                return mid
            else:
                r = mid - 1

        return r
