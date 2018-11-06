class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        # 创建一个以列表元素为键,对应的索引为值的字典
        hashmap = {}
        for i, k in enumerate(nums):
            hashmap[k] = i
        # 遍历字典,通过比较数值(两数之和等于target)和索引(两数索引不能相同)来找到列表中的目标元素
        # 并返回对应的索引,
        for i, k in enumerate(nums):
            b = target - k
            if b in hashmap and hashmap.get(b) != i:
                return i, hashmap.get(b)
