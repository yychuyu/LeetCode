class NumArray:
    """
    DP
    """

    def __init__(self, nums: List[int]):
        if not nums:
            return None 
        l = len(nums)+1
        self.ret = [0] * (l)
        self.ret[0], self.ret[1] = 0, nums[0]
        for i in range(2,l):
            self.ret[i] = self.ret[i-1] + nums[i-1]
        #print(f"self.ret:{self.ret}")

    def sumRange(self, i: int, j: int) -> int:
        return self.ret[j+1] - self.ret[i]        


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(i,j)
