package algorithm._088_merge;
/*
 给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。
说明:
	初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
	你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
示例:
	输入:
		nums1 = [1,2,3,0,0,0], m = 3
		nums2 = [2,5,6],       n = 3
	输出: [1,2,2,3,5,6]
*/

public class Merge {

	public static void main(String[] args) {
		int[] nums1 = { 4, 5, 6, 0, 0, 0 };
		int[] nums2 = { 1, 2, 3 };
		int m = 3;
		int n = 3;
		merge(nums1, 3, nums2, 3);
		for (int i = 0; i < nums1.length; i++) {
			System.out.println(nums1[i]);
		}
	}

	//根据题目 : nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素
	//思路 : 比较num1[m]与num2[n]中的数,由后往前将较大的插入到nums1中,直到m ,n其中一个为0,
	//		当m=0即将nums2中剩余的元素插入到nums1中,否则nums1即为最后的有序数组了
	public static void merge(int[] nums1, int m, int[] nums2, int n) {
		int i = nums1.length - 1;
		for (; i >= 0; i--) {
			if (m == 0 || n == 0) {
				break;
			}
			if (nums1[m - 1] > nums2[n - 1]) {
				nums1[i] = nums1[m - 1];
				m--;
			} else {
				nums1[i] = nums2[n - 1];
				n--;
			}
		}
		if (m == 0) {
			while (n != 0) {
				nums1[i] = nums2[n - 1];
				i--;
				n--;
			}
		}
	}
}
