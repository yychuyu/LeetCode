package cn.plummy;

/**
 * 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的 两个 整数。
 * 你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
 * 示例:
 * 给定 nums = [2, 7, 11, 15], target = 9
 * 因为 nums[0] + nums[1] = 2 + 7 = 9 所以返回 [0, 1]
 * @author lilin
 */
public class Test0001 {
	public static void main(String[] args) {
		int [] res = new Test0001().twoSum(new int[]{2, 7, 11, 15}, 9);
		for (int temp : res) {
			System.out.print(temp + "\t");
		}
	}
	
	/**
	 * 第一数依次和后面每个数求和,当满足和等于target,就返回两个数在数组中的下标值
	 * @param nums
	 * @param target
	 * @return
	 */
	public int[] twoSum(int[] nums, int target) {
		for (int i = 0; i <= nums.length - 1; i++) {
			for (int j = i + 1; j <= nums.length; j++) {
				if (nums[i] + nums[j] == target) {
					return new int[]{i,j};
				}
			}
		}
		return null;
	}
}
