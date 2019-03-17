class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        List<Integer> result = new ArrayList<Integer>();
        int len = nums.length;
        for (int i = 0; i < len; i++) {
            //轮流把数组中的数字（绝对值）减 1，，然后和数组下组联系起来，取对应位置的数据，并把它置为相反数；设置失败的数字（仍是正数）的下标加 1 即为我们需要的数字；
            if (nums[Math.abs(nums[i]) - 1] > 0) {
                nums[Math.abs(nums[i]) - 1] *= -1;
            }
        }
        for (int i = 0; i < len; i++) {
            if (nums[i] > 0) {
                result.add(i + 1);
            }
        }
        return result;
    }
}