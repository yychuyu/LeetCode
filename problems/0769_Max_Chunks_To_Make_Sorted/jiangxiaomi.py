class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        count = 0
        for key,value in  enumerate(arr):
            if key == max(arr[:key+1]):
                count +=1
        return count