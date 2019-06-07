class Solution:
    def matrixReshape(self, nums: List[List[int]], r: int, c: int) -> List[List[int]]:
        total_len = 0
        nums_one = []
        for lst in nums:
            total_len += len(lst)
            nums_one += lst
        if r * c != total_len:
            return nums
        # print(f"nums_one{nums_one}")

        nums_ret = []
        for i in range(0, r):
            j = i * c
            nums_ret.append(nums_one[j : j + c])
        return nums_ret
