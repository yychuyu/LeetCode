/*
给定一个未排序的数组，判断这个数组中是否存在长度为 3 的递增子序列。

		数学表达式如下:

		如果存在这样的 i, j, k,  且满足 0 ≤ i < j < k ≤ n-1，
		使得 arr[i] < arr[j] < arr[k] ，返回 true ; 否则返回 false 。
		说明: 要求算法的时间复杂度为 O(n)，空间复杂度为 O(1) 。

		示例 1:

		输入: [1,2,3,4,5]
		输出: true
		示例 2:

		输入: [5,4,3,2,1]
		输出: false
*/

public class Solution {
    public boolean increasingTriplet(int[] nums) {
        // 记录目前为止最小的数字
        int min = Integer.MAX_VALUE;
        // 记录目前为止第二小的数字
        int min2 = Integer.MAX_VALUE;
        for (int n : nums) {
            // min最小的数字
            if (n <= min)
                min = n;
                // n>min,但是比min2小，更新
            else if (n <= min2)
                min2 = n;
            else
                // n>min2>min返回true
                return true;
        }
        return false;
    }
}