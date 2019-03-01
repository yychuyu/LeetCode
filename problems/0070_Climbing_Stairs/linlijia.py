class Solution:
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        list = [1, 2];
        for i in range(2, n, 1):
            list.append(list[i - 2] + list[i - 1]);
        return list[n - 1];
        