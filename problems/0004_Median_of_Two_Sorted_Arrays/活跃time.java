/**
 * MySolution.java
 * top.actim.leetcode._4_Median_of_Two_Sorted_Arrays
 *
 * Function： TODO 
 *
 *   ver     date      		author
 * ──────────────────────────────────
 *   		 2019年4月8日 		a
 *
 * Copyright (c) 2019, TNT All Rights Reserved.
*/

package top.actim.leetcode._4_Median_of_Two_Sorted_Arrays;

import java.util.ArrayList;
import java.util.Collections;

public class MySolution {

	public static void main(String[] args) {
		Solution s = new Solution();
		int[] nums1 = { 1, 2, 3 };
		int[] nums2 = { 4, 5, 6};
		System.out.println(s.findMedianSortedArrays(nums1, nums2));
	}

}

//没达到复杂度要求
class Solution {
	public double findMedianSortedArrays(int[] nums1, int[] nums2) {
		// 排序
		ArrayList<Integer> num = new ArrayList<Integer>();

		for (Integer in : nums1) {
			num.add(in);
		}

		for (Integer in : nums2) {
			num.add(in);
		}

		Collections.sort(num);

		// 取中位数
		if (num.size() % 2 == 0) {
			int mid1 = num.size() / 2 - 1;
			int mid2 = (int) Math.ceil(num.size() / 2.0);

			System.out.println(mid1);
			System.out.println(mid2);

			return (num.get(mid1) + num.get(mid2)) / 2.0;
		} else {
			return num.get(num.size() / 2);
		}
	}
}
