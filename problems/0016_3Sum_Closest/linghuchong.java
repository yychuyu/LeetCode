class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int sum = Integer.MAX_VALUE;
        int diff = Integer.MAX_VALUE;
        for(int k=0;k<nums.length-2;k++){
            int val = target - nums[k];
            for(int i=k+1, j=nums.length-1;i<j;){
                int d = val - nums[i] - nums[j];
                if(d==0)
                    return target;
                
                if(d<0){
                    j--;
                }
                else{
                    i++;
                }
                
                int abs = Math.abs(d);
                if(diff>abs){
                    diff = abs;
                    sum = target - d;
                }
            }
        }
        return sum;
    }
}