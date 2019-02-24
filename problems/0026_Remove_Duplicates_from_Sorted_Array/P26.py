#python3 emmmleetcode这个东西就只要实现的类的方法，其他的并没有构建，额，懒一点就这样写了
class Solution:
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        length = len(nums)
        if length < 2:
            return length
        cur = 0
        for i in range(1, length):
            if nums[i] != nums[cur]:
                cur += 1
                nums[cur] = nums[i]
        return cur + 1
