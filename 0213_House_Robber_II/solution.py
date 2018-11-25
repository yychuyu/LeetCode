# Referred to jkmetal
class Solution:
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        N = len(nums)
        if N == 0:
            return 0
        if N == 1:
            return nums[0]
                
        # The interval between the chosen rooms can be 2,3,...,N-2.
        # Each interval can be different.
        # Directly solution: listing maybe O(N!) possibilities
        # Actually, if choose interval 4, why not choose 2 for twice which is available?
        # Therefore, the different intervals reduce to be 2 and 3
        # Only need to compare the 
        
        # DP problems
        res_with_head = [0 for _ in range(N)]
        res_with_head[0] = nums[0]
        res_with_head[1] = nums[1]
        res_no_head = [0 for _ in range(N)]
        res_no_head[0] = 0
        res_no_head[1] = nums[1]
        
        max_res = max(res_with_head[0], res_with_head[1])
        for i in range(2,N):
            res_with_head[i] = nums[i] + max(res_with_head[i-2], (res_with_head[i-3] if i>=3 else 0))  
            res_no_head[i] = nums[i] + max(res_no_head[i-2], (res_no_head[i-3] if i>=3 else 0))  
            if i == N-1:
                max_res = max(max_res, res_no_head[i])
            else:
                max_res = max(max_res, res_with_head[i])
        
        return max_res
            
        
    
                    
        
