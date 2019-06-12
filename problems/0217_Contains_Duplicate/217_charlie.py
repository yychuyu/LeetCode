class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        after_set_list = list(set(nums))
        if len(after_set_list) != len(nums):
            return True
        else:
            return False
