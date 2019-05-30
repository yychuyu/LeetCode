class Solution:
    def matrixReshape(self, nums: List[List[int]], r: int, c: int) -> List[List[int]]:
        # can't reshape (示例 2)
        if len(nums) * len(nums[0]) != r * c:
            return nums
        # can reshape (示例 1)
        temp = sum(nums, [])
        new_matrix = [[0 for j in range(c)] for i in range(r)]
        for index_new_row in range(r):
            for index_new_column in range(c):
                new_matrix[index_new_row][index_new_column] = temp[index_new_row * c + index_new_column]
        return new_matrix
