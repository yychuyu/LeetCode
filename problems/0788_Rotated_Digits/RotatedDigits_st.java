package algorithm._788_rotatedDigits;
/*
���ǳ�һ���� X Ϊ����, �������ÿλ��������ر���ת 180 �Ⱥ������Կ��Եõ�һ����Ч�ģ��Һ� X ��ͬ������
Ҫ��ÿλ���ֶ�Ҫ����ת��
���һ������ÿλ���ֱ���ת�Ժ���Ȼ����һ�����֣� �����������Ч�ġ�
0, 1, �� 8 ����ת����Ȼ�������Լ���2 �� 5 ���Ի�����ת�ɶԷ���6 �� 9 ͬ��
������Щ����������������ת�Ժ󶼲�������Ч�����֡�
����������һ�������� N, ����� 1 �� N ���ж��ٸ��� X �Ǻ�����
ʾ��:
	����: 10
	���: 4
����: 
	��[1, 10]�����ĸ������� 2, 5, 6, 9��
	ע�� 1 �� 10 ���Ǻ���, ��Ϊ��������ת֮�󲻱䡣
ע��:
	N ��ȡֵ��Χ�� [1, 10000]��
*/

public class RotatedDigits {
	public static void main(String[] args) {
		System.out.println(rotatedDigits(6000));
	}

	//˼· : ����1��N,��һ�����ж����ǲ��Ǻ���,һ��������һλ��һλ���Ľ�����ת
	//		���һ�����д���3,4,7����Ҫ�ٽ����ж�,����ת���е������һ��λ��
	//		���ж�����ԭ���Ƿ����(����%,/������������ȡ��)
	//�Ż� : ���λ��������Ϊ3,4,7��ֱ��������λ��Ϊ3,4,7����
	//		�� : 5400�ڶ�λ��Ϊ4,������һ����������Ϊ5500
	//			���ÿ���ʲô5426,����һ����������Ϊ5526���м��һЩ��û�б�����,
	//			��Ϊ��������5426ǰ�ػ������5400,���Ի�ֱ��������5500
	//�ⷨ : ����һ��s���洢�����ĸ���,����һ��i���ڱ���,
	//		����һ��digits����ʾ��ǰ���������Ǽ�λ��(��1,10,100��10�ı�����ʾ)
	//		����һ��temp��tempdigits������ȡ���Ĳ���,
	//		����һ��tempresult���洢ȡ�������������ж�,
	//		����һ��result���洢��ת�������,�����жϵ�ǰ�����������Ƿ�Ϊ����
	public static int rotatedDigits(int N) {
		int s = 0;
		int i = 1;
		int digits = 1;
		int tempdigits = 1;
		int temp = 1;
		int tempresult = 1;
		int result = 0;
		while (i <= N) {
			result = 0;
			if (i == (digits * 10)) {
				digits *= 10;
			}
			temp = i;
			tempdigits = digits;
			while (tempdigits != 0) {
				tempresult = temp / tempdigits;
				if (tempresult == 3 || tempresult == 4 || tempresult == 7) {
					i += tempdigits - 1;
					break;
				} else if (tempresult == 2) {
					tempresult = 5;
				} else if (tempresult == 5) {
					tempresult = 2;
				} else if (tempresult == 6) {
					tempresult = 9;
				} else if (tempresult == 9) {
					tempresult = 6;
				}
				result += tempresult * tempdigits;
				if (tempdigits == 1 && result != i) {
					s++;
				}
				temp %= tempdigits;
				tempdigits /= 10;
			}
			i++;
		}
		return s;
	}
}
