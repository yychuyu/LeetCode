class Solution {
    public int removeElement(int[] nums, int val) {
        int length = nums.length;
        for (int i=0; i<length; i++) {
            if (nums[i] == val) {
                nums[i] = nums[length-1];
                length--;
                i--;
            }
        }
        return length;
    }
}
