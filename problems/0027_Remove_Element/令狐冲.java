


class Solution {
    public int removeElement(int[] nums, int val) {
        int i = 0;
        int pointer = nums.length -1;
        while(i<= pointer){
            if (nums[i] == val){
                nums[i]=nums[pointer];
                pointer--;
            }else{
                i++;
            }
        }
        return pointer+1;
    }
}