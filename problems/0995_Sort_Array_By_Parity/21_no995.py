class Solution:
    def sortArrayByParity(self, A: List[int]) -> List[int]:
      # more pythonic
    result = list(filter(lambda x: x % 2 == 0, A)) + list(filter(lambda x: x % 2 != 0, A))
    return result
