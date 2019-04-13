class Solution(object):
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        from functools import reduce
        from operator import mul
        dic = {}
        s = 1
        # ans = []
        if 0 in nums:
            # ans.append(0)
            ans = 0
        else:
            ans = nums[0]
        for i in nums:
            if not i:
                s += 1
                continue
            try:
                dic[s].append(i)
            except:
                dic[s] = [i]
        for v in dic.values():
            ret = reduce(mul, v)
            # ans.append(ret)
            if ret > ans:
                ans = ret
            if ret < 0:
                for j in range(len(v)):
                    if v[j] < 0 and j < len(v) - 1:
                        ret = reduce(mul, v[j + 1:])
                        if ret > ans:
                            ans = ret
                        break
                for k in range(len(v) - 1, 0, -1):
                    if v[k] < 0:
                        ret = reduce(mul, v[:k])
                        if ret > ans:
                            ans = ret
                        break

        return ans


if __name__ == '__main__':
    washing = Solution()
    li = [0, 1, 43, 5, 0, 0, 4, 77, 2, 1, 0, -3, -23, -44, 0, 8]
    # li = [0, 0, 0, 0, 0, 0, 0]
    print(washing.maxProduct(li))
