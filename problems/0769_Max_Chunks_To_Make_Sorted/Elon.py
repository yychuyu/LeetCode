class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        maxval, result = 0, 0
        for index,num in enumerate(arr):
            maxval = max(maxval, num)
            if index == maxval:
                result += 1
        return result
                