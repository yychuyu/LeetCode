package algorithm._066_plusOne;

/*
����һ����������ɵķǿ���������ʾ�ķǸ��������ڸ����Ļ����ϼ�һ��
���λ���ִ�����������λ�� ������ÿ��Ԫ��ֻ�洢һ�����֡�
����Լ���������� 0 ֮�⣬��������������㿪ͷ��
ʾ�� 1:
	����: [1,2,3]
	���: [1,2,4]
	����: ���������ʾ���� 123��
ʾ�� 2:
	����: [4,3,2,1]
	���: [4,3,2,2]
	����: ���������ʾ���� 4321��
*/

public class PlusOne {
	public static void main(String[] args) {
		int[] nums = { 9 };
		int[] result = plusOne(nums);
		for (int val : result) {
			System.out.println(val);
		}
	}

	//˼· : ����һ��boolean���͵����ж��Ƿ���Ҫ���Ͻ�һλ,����һλ����Ҫ���Ͻ�һλʱ,
	//		����Ҫ����һ�����ȱ�ԭ���鳤�ȴ�һ������,ʹ���һλ����һ,ʣ�������digits������ͬ
	public static int[] plusOne(int[] digits) {
		boolean isCeil = true;
		int index = digits.length - 1;
		while (isCeil && index >= 0) {
			digits[index] += 1;
			if (digits[index] == 10) {
				isCeil = true;
				digits[index] = 0;
			} else {
				isCeil = false;
			}
			index--;
		}
		if (isCeil) {
			int[] result = new int[digits.length + 1];
			result[0] = 1;
			for (int i = 1, j = 0; i < result.length - 1; i++, j++) {
				result[i] = digits[j];
			}
			return result;
		}
		return digits;
	}
}
