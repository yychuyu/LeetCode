from collections import Counter
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        return [d[0] for d in Counter(nums).most_common(k)]
