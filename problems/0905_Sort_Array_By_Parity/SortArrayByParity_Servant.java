package algorithm._905_sortArrayByParity;
/*
����һ���Ǹ��������� A������һ���� A ������ż��Ԫ����ɵ����飬����� A ����������Ԫ�ء�
����Է���������������κ�������Ϊ�𰸡�
ʾ����
	���룺[3,1,2,4]
	�����[2,4,3,1]
	��� [4,2,3,1]��[2,4,1,3] �� [4,2,1,3] Ҳ�ᱻ���ܡ�
��ʾ��
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

	//�½�һ�������������������Ԫ��,����ԭ����,��Ϊż�����뵽�������ǰ��,Ϊ��������뵽������ĺ���
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
