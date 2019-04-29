class Solution {
    public int maxSubArray(int[] nums) {
        
        int res = nums[0];
        int sum = 0;//res始终记录的是最大值
        for (int num : nums) {
            if (sum > 0)//只要前面的和大于0，就继续加下去
                sum += num;
            else//前面的数和是负数，哪后一个就是最大值，不用加前面的
                sum = num;
            res = Math.max(res, sum);  //所有的累加的值与最大值比较
        }
        return res;
    }
}