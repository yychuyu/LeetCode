class Solution {
    public int maxSubArray(int[] nums) {
     
		int max = nums[0];
		// res[x] 表示从 0 到 x 的最大连续数组的和
		int[] res = new int[nums.length];
		res[0] = nums[0];
		
		for (int i = 1; i < nums.length; i++) {
            res[i] = Math.max(res[i - 1] + nums[i], nums[i]);
			max = Math.max(res[i], max);
		}	
		
		return max;
		
    }
}