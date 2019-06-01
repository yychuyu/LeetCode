class Solution(object):
    def matrixReshape(self, nums, r, c):
        """
        :type nums: List[List[int]]
        :type r: int
        :type c: int
        :rtype: List[List[int]]
        """
        if len(nums) * len(nums[0]) != r * c:
            return nums

        li = []
        for i in nums:
            for j in i:
                li.append(j)

        li.reverse()

        ret = []
        for i in range(r):
            ret.append([])

        for k in range(r):
            for _ in range(c):
                ret[k].append(li.pop())

        return ret


if __name__ == '__main__':
    s = Solution()
    print(s.matrixReshape([[1, 2], [3, 4], [5, 6], [7, 8]], 2, 4))
