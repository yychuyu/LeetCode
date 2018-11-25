class Solution {
    public int[] twoSum(int[] nums, int target) {
       HashMap<Integer, Integer> h = new HashMap<Integer, Integer>();
        int[] a = new int[2];
        for (int i = 0; i < nums.length; ++i) {
            h.put(nums[i], i);
        }
        for (int i = 0; i < nums.length; ++i) {
            int t = target - nums[i];
            if (h.containsKey(t) && h.get(t) != i) {
                a[0] = i;
                a[1] = h.get(t);
                break;
            }
        }
        return a;
    }
}