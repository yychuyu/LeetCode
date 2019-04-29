class Solution {
    public int findKthLargest(int[] nums, int k) {
        // 经过调优的快速排序法
        Arrays.sort(nums);
        return nums[nums.length-k];
    }
}
