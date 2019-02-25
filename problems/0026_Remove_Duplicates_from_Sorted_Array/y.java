//微信：y
class Solution {
    public int removeDuplicates(int[] nums) {
        int pointer1 = -1;
        int pointer2 = 0;
        int tmp = Integer.MAX_VALUE;
        int[] result = new int[nums.length];
        for(; pointer2<nums.length;){
            if( tmp == nums[pointer2] ){
                pointer2++;
            }else{
                pointer1++;
                tmp = nums[pointer2];
                nums[pointer1] = tmp;
                pointer2++;
            }
        }
        return (pointer1+1);
    }
}