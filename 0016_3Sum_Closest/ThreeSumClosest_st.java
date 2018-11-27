package algorithm._016_threeSumClosest;
/*
给定一个包括 n 个整数的数组 nums 和 一个目标值 target。
找出 nums 中的三个整数，使得它们的和与 target 最接近。
返回这三个数的和。假定每组输入只存在唯一答案。
	例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.
	与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
*/

import java.util.Arrays;

public class ThreeSumClosest {
	public static void main(String[] args) {
		int[] nums = { -3, 0, 1, 2 };
		System.out.println(threeSumClosest(nums, 1));
	}

	//思路 : 将数组进行排序,然后遍历确定一个数,头尾双指针跳跃来确定另外两个数
	//		定义一个result来存放更新满足的答案,如果target值与三数之和相等则直接返回
	//		否则判断target值与三数之和的差的绝对值来判断当前是否需要更新result值
	//解答 : 遍历取一个数,另外两个数分别为当前遍历的数的下一个数与最后一个数,
	//		在头指针的数小于尾指针的数的前提下,当三数之和与target相等则直接返回,
	//  	如果三个数的和小于target,则头指针移动,否则尾指针移动
	//		判断target值与三数之和的差的绝对值来判断当前是否需要更新result值
	public static int threeSumClosest(int[] nums, int target) {
		if (nums.length == 3) {
			return nums[0] + nums[1] + nums[2];
		}
		Arrays.sort(nums);
		int left;
		int right;
		int temp;
		int result = nums[0] + nums[1] + nums[2];
		for (int i = 0; i < nums.length; i++) {
			left = i + 1;
			right = nums.length - 1;
			while (left < right) {
				temp = (nums[i] + nums[left] + nums[right]);
				if (temp == target) {
					return temp;
				} else if (temp < target) {
					left++;
				} else {
					right--;
				}
				if (Math.abs(temp - target) < Math.abs(result - target)) {
					result = temp;
				}
			}
		}
		return result;
	}
}
