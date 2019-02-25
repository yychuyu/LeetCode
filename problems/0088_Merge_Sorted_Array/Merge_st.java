package algorithm._088_merge;
/*
 �������������������� nums1 �� nums2���� nums2 �ϲ��� nums1 �У�ʹ�� num1 ��Ϊһ���������顣
˵��:
	��ʼ�� nums1 �� nums2 ��Ԫ�������ֱ�Ϊ m �� n��
	����Լ��� nums1 ���㹻�Ŀռ䣨�ռ��С���ڻ���� m + n�������� nums2 �е�Ԫ�ء�
ʾ��:
	����:
		nums1 = [1,2,3,0,0,0], m = 3
		nums2 = [2,5,6],       n = 3
	���: [1,2,2,3,5,6]
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

	//������Ŀ : nums1 ���㹻�Ŀռ䣨�ռ��С���ڻ���� m + n�������� nums2 �е�Ԫ��
	//˼· : �Ƚ�num1[m]��num2[n]�е���,�ɺ���ǰ���ϴ�Ĳ��뵽nums1��,ֱ��m ,n����һ��Ϊ0,
	//		��m=0����nums2��ʣ���Ԫ�ز��뵽nums1��,����nums1��Ϊ��������������
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
