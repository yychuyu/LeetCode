package algorithm._215_findKthLargest;

/*
��δ������������ҵ��� k ������Ԫ�ء���ע�⣬����Ҫ�ҵ������������ĵ� k ������Ԫ�أ������ǵ� k ����ͬ��Ԫ�ء�
ʾ�� 1:
	����: [3,2,1,5,6,4] �� k = 2
	���: 5
ʾ�� 2:
	����: [3,2,3,1,2,4,5,5,6] �� k = 4
	���: 4
˵��:
	����Լ��� k ������Ч�ģ��� 1 �� k �� ����ĳ��ȡ�
*/

public class FindKthLargest {
	public static void main(String[] args) {
		System.out.println(findKthLargest(new int[] { 3, 2, 1, 5, 6, 4 }, 2));
	}

	//˼· : ��Ϊȡ��k�����ֵ,���Խ�������k�κ���Ѿ��ҵ�����,����ľͲ����ٽ���������,
	//		��Ϊ����������0��ʼ,������k���ֵ��Ϊ�������������Ϊk-1��ֵ
	//�ⷨ : 26-34�н����˽��������ǰk��,��ʱ�����ǰk��ֵ���Ѿ���ȫ�˽���������,
	//		��ʱ����k-1��ֵ����
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
