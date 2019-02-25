class Solution {
    public int threeSumClosest(int[] nums, int target) {
        
        
        int res = nums[0] + nums[1] + nums[2];
		Arrays.sort(nums);
        
        for (int i  = 0; i < nums.length - 2; i++) {
			int left = i + 1;
			int right = nums.length - 1;
			
			while (left != right) {
				int t = nums[i] + nums[left] + nums[right];
				if (t == target) {
				   return t;	
				}
				
				if (Math.abs(res - target) >  Math.abs(t - target)) {
					res = t;
				}
				
				if (t > target) {
					right--;
				} else {
					left++;	
				}	
			}	
        }
		
		return res;
    }
}