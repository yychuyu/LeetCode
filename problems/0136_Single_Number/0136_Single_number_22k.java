class Solution {
    public int singleNumber(int[] nums) {
         Set<Integer> set = new HashSet<>();//Create the Set
        for (int i = 0; i < nums.length; i++) {
            if (!set.add(nums[i])) 
                 set.remove(nums[i]); // remove the repeat number    
        }
         return set.iterator().next();//return the final result   
        /*
        Another solution:
    public int singleNumber(int[] nums) {
        int ans =0; 
        int len = nums.length;
        for(int i=0;i!=len;i++)
        //if the two numbers are equal.
        //The result will no change 
        ans ^= nums[i];
        return ans;
        }
        */
    }
}