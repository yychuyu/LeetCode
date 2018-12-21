package algorithm._215_findKthLargest;

/*
在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
示例 1:
	输入: [3,2,1,5,6,4] 和 k = 2
	输出: 5
示例 2:
	输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
	输出: 4
说明:
	你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。
*/

public class FindKthLargest {
	public static void main(String[] args) {
		System.out.println(findKthLargest(new int[] { 3, 2, 1, 5, 6, 4 }, 2));
	}

	//思路 : 因为取第k个大的值,所以降序排序k次后就已经找到答案了,后面的就不用再进行排序了,
	//		因为数组索引从0开始,索引第k大的值则为降序排序后索引为k-1的值
	//解法 : 26-34行进行了降序排序的前k次,此时数组的前k个值即已经完全了降序排序了,
	//		此时返回k-1的值即可
	public static int findKthLargest(int[] nums, int k) {
		for (int i = 0; i < k; i++) {
			for (int j = nums.length - 1; j > i; j--) {
				if (nums[j] > nums[j - 1]) {
					int temp = nums[j];
					nums[j] = nums[j - 1];
					nums[j - 1] = temp;
				}
			}
		}
		return nums[k - 1];
	}
}
