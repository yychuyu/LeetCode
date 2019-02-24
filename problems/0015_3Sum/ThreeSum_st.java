package algorithm._015_threeSum;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
/*
给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？
找出所有满足条件且不重复的三元组。
注意：答案中不可以包含重复的三元组。
	例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
	满足要求的三元组集合为：
	[
  		[-1, 0, 1],
  		[-1, -1, 2]
	]
*/

public class ThreeSum {
	public static void main(String[] args) {
		int[] nums = { -4, -1, -1, 0, 1, 2 };
		List<List<Integer>> list = threeSum(nums);
		for (List<Integer> l : list) {
			System.out.println(l);
		}
	}

	//思路 : 将数组进行排序,然后遍历确定一个数,头尾双指针跳跃来确定另外两个数
	//		需要注意题目要求不得出现重复的答案,可先用set集合排除重复答案,也可自己进行判断
	//解答 : 遍历取一个数,另外两个数分别为当前遍历的数的下一个数与最后一个数,
	//		在头指针的数小于尾指针的数的前提下,如果三个数的和小于0,则头指针移动,否则尾指针移动
	//  	当遍历的数与上个数相等则继续遍历 (不得出现重复的答案)
	//		当满足答案时,令头指针移动,此时需要注意头指针的数于之前的数是否相等,
	//		要使它进行判断 (不得出现重复答案)
	public static List<List<Integer>> threeSum(int[] nums) {
		List<List<Integer>> result = new ArrayList<List<Integer>>();
		Arrays.sort(nums);
		int left;
		int right;
		int temp;
		for (int i = 0; i < nums.length; i++) {
			if (i > 0 && nums[i] == nums[i - 1]) {
				continue;
			}
			left = i + 1;
			right = nums.length - 1;
			while (left < right) {
				temp = (nums[i] + nums[left] + nums[right]);
				if (temp == 0) {
					List<Integer> list = new ArrayList<Integer>();
					list.add(nums[i]);
					list.add(nums[left]);
					list.add(nums[right]);
					result.add(list);
					left++;
					while (left < right && nums[left] == nums[left - 1]) {
						left++;
					}
				} else if (temp < 0) {
					left++;
				} else {
					right--;
				}
			}
		}
		return result;
	}

}
