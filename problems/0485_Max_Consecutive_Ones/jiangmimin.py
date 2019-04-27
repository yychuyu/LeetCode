class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        count = 0
        maxvalue = 0
        for i in nums:
            if i == 1:
                count += 1
            else:
                if count > maxvalue:
                    maxvalue = count
                count = 0
        if count > maxvalue:
            return count
        return maxvalue