/**
     * * @Description
     * *给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，
		使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。
     * * @Author 22k
     * * @Email 8430177@qq.com
     * * @Date 2018-11-21
     **/
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        HashSet<List<Integer>> set = new HashSet<>();
        List<List<Integer>> result = new ArrayList<>();
        Arrays.sort(nums);//排序数组
        for (int i = 0; i < nums.length - 2; i++) {
            int left = i + 1, right = nums.length - 1, target = -nums[i];
            while (left < right) {
                int sum = nums[left] + nums[right];
                if (sum < target) {
                    left++;
                } else if (sum > target) {
                    right--;
                } else {
                    List<Integer> temp = new ArrayList<>();
                    temp.add(nums[i]);
                    temp.add(nums[left++]);
                    temp.add(nums[right--]);
                    set.add(temp);//去重
                }
            }
        }
        for (List<Integer> list : set)
            result.add(list);
        return result;
    }

}