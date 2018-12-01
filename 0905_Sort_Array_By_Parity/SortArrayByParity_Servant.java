package algorithm._905_sortArrayByParity;
/*
给定一个非负整数数组 A，返回一个由 A 的所有偶数元素组成的数组，后面跟 A 的所有奇数元素。
你可以返回满足此条件的任何数组作为答案。
示例：
	输入：[3,1,2,4]
	输出：[2,4,3,1]
	输出 [4,2,3,1]，[2,4,1,3] 和 [4,2,1,3] 也会被接受。
提示：
	1 <= A.length <= 5000
	0 <= A[i] <= 5000
*/
public class SortArrayByParity {
	public static void main(String[] args) {
		int[] arr = { 1, 54, 32, 5, 6, 3, 6, 34, 4, 5, 2, 123, 4, 32, 56, 56, 3,
				4, 6 };
		int[] newarr = sortArrayByParity(arr);
		for (int val : newarr) {
			System.out.println(val);
		}
	}

	//新建一个数组用来存放排序后的元素,遍历原数组,当为偶数插入到新数组的前面,为奇数则插入到新数组的后面
	public static int[] sortArrayByParity(int[] A) {
		int[] arr = new int[A.length];
		int beg = 0;
		int end = A.length - 1;
		for (int i = 0; i < A.length; i++) {
			if (A[i] % 2 == 0) {
				arr[beg] = A[i];
				beg++;
			} else {
				arr[end] = A[i];
				end--;
			}
		}
		return arr;
	}
}
