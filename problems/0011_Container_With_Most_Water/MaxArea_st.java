package algorithm._011_maxArea;
/*
���� n ���Ǹ����� a1��a2��...��an��ÿ�������������е�һ���� (i, ai) ��
�������ڻ� n ����ֱ�ߣ���ֱ�� i �������˵�ֱ�Ϊ (i, ai) �� (i, 0)��
�ҳ����е������ߣ�ʹ�������� x �Ṳͬ���ɵ�����������������ˮ��
˵�����㲻����б�������� n ��ֵ����Ϊ 2��
	ͼ�д�ֱ�ߴ����������� [1,8,6,2,5,4,8,3,7]���ڴ�����£������ܹ�����ˮ����ʾΪ��ɫ���֣������ֵΪ 49��
ʾ��:
	����: [1,8,6,2,5,4,8,3,7]
	���: 49	
*/

public class MaxArea {
	public static void main(String[] args) {
		System.out.println(maxArea(new int[] { 1, 8, 6, 2, 5, 4, 8, 3, 7 }));
	}

	//˼· : Ҫ�����ľ������,��Ϊ��Խ��,��Խ��,�������Ҳ�����
	//		��˲���˫ָ��ķ���,�������ͷβ��ʼ�ƶ�,��ʱһ��ʼ����Ϊ���,
	//		����ͷβָ����ָ���ֵ���������εĿ�,�ĸ�ֵ�����ĸ�ֵ��Ϊ��,
	//		�����ƶ�ֵ�͵��Ǹ�ָ��,����ֵ�ߵ�,��������ȷ���������εĿ�ᴦ�ڸ��ߵ�ֵ
	//�ⷨ : ����ͷβָ���Լ��洢����������ʱ���ͷβָ����ָ���ֵ�͵��Ǹ�������Ϊ���ο�
	//		30��ʵ������ͷβָ����ָ���ֵ�нϵ͵��Ǹ�ֵ,
	//		31��ʵ����������ֵ�ĸ���,���ȵ�ǰ�Ƚϵľ���������򲻱�
	public static int maxArea(int[] height) {
		int area = 0;
		int temp;
		int left = 0;
		int right = height.length - 1;
		while (left < right) {
			temp = height[left] < height[right] ? height[left] : height[right];
			area = area < (right - left) * temp ? (right - left) * temp : area;
			if (height[left] < height[right]) {
				left++;
			} else {
				right--;
			}
		}
		return area;

		//�����ⷨ,ûʲô��˵��
		/*int area = 0;
		int temp = 0;
		for (int i = 0; i < height.length; i++) {
			for (int j = i + 1; j < height.length; j++) {
				if (height[i] > height[j]) {
					temp = height[j];
				} else {
					temp = height[i];
				}
				if (area < temp * (j - i)) {
					area = temp * (j - i);
				}
			}
		}
		return area;*/
	}
}
