/**
 * * @ClassName NumArray
 * * @Description TODO
 * * @Author luoquan
 * * @Email luo.quan@aliyun.com
 * * WeChat luo_quan1982
 * * @Date 2018/11/8 15:27
 **/

class NumArray {

    private int[] sum;

    public NumArray(int[] nums) {
        sum = new int[nums.length + 1];
        sum[0] = 0;
        for (int i = 0; i < sum.length - 1; i++) {
            sum[i + 1] = sum[i] + nums[i];
        }
    }

    public int sumRange(int i, int j) {
        return sum[j + 1] - sum[i];
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */