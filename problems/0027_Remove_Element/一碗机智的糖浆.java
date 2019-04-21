class Solution {
    public int removeElement(int[] nums, int val) {
        //就地删除给定值的所有元素
        // O(1) 的额外空间来处理
        int i=0;
        for(int j=0;j<nums.length;j++){
            if(nums[j]!=val){//只要数值不等于val就把值赋给nums[i]，新的数组O（1）额外的空间
                nums[i]=nums[j];
                i++;
            }
        }
        //返回新数组长度
        return i;
    }
}