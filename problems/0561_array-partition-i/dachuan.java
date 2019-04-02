class Solution {
    public int arrayPairSum(int[] nums) {
        //综合来看，先对数组进行排序，然后从第一个元素起，隔两个元素加一次，这样能得到的和最大；
        Arrays.sort(nums);
        int sum = 0;
        for (int i = 0; i < nums.length; i += 2) {
            sum += nums[i];
        }
        return sum;
    }
}