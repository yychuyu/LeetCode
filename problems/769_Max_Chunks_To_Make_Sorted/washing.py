class Solution(object):
    def maxChunksToSorted(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        count = 0
        sorted_arr = sorted(arr)
        list_arr, list_sorted_arr = [], []
        for i, j in zip(arr, sorted_arr):
            list_arr.append(i)
            list_sorted_arr.append(j)
            if sorted(list_arr) == list_sorted_arr:
                list_arr, list_sorted_arr = [], []
                count += 1
                continue
        return count


if __name__ == '__main__':
    solution = Solution()
    print(solution.maxChunksToSorted([1, 3, 5, 7, 8, 6, 4, 2, 0]))
    print(solution.maxChunksToSorted([4, 3, 2, 1, 0]))
    print(solution.maxChunksToSorted([1, 0, 2, 3, 4]))
    print(solution.maxChunksToSorted([]))
