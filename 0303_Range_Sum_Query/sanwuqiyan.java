class NumArray {
    private int[] sums;

    public NumArray(int[] nums) {
        sums = new int[nums.length+1];

        sums[0] = 0;
        for (int i = 1; i <= nums.length; i++) {
            sums[i] += sums[i-1] + nums[i-1];
        }
    }

    public int sumRange(int i, int j) {
            return sums[j+1] - sums[i];
    }
    
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */