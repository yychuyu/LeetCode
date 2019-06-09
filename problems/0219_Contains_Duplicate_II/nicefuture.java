class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        // 使用滑动窗口 side window，每次检查滑动窗口内部是否包含新进入窗口的数字
        Set<Integer> set = new HashSet<Integer>();
        for (int i=0; i<nums.length; i++) {
            if (i > k) set.remove(nums[i-k-1]);
            if (!set.add(nums[i])) return true;
        }
        return false;
    }
}
