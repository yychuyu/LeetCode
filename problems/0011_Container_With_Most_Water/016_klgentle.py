class Solution:
    """
    双指针 Double pointer
    容器面积 = 底*高
    构建左右两个指针,对应的容器面积 = 指针间的距离 * 两指针对应的较小高度
    要求最大的面积,则底要尽量大,高要尽量高.
    所以两个指针最好一左一右,一个在左端点,一个在右端点, 此时底最大; 
    为了让高最大,丢弃高度小的指针,将指针向高度大的指针移动.
    """
    #@pysnooper.snoop()
    def maxArea(self, height: "list[int]") -> int:
        res = 0
        l = 0
        r = len(height) - 1
        while l < r:
            area = (r - l) * min(height[l], height[r])
            res = max(res, area)
            # 保留高度最大的垂线,将指针由低的垂线往高处移动 
            # KEEP THE MAX HEIGHT
            if height[l] < height[r]:
                l += 1
            else:
                r -= 1

        print(res)
        return res
