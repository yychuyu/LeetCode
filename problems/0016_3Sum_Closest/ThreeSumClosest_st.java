package algorithm._016_threeSumClosest;
/*
����һ������ n ������������ nums �� һ��Ŀ��ֵ target��
�ҳ� nums �е�����������ʹ�����ǵĺ��� target ��ӽ���
�������������ĺ͡��ٶ�ÿ������ֻ����Ψһ�𰸡�
	���磬�������� nums = [-1��2��1��-4], �� target = 1.
	�� target ��ӽ����������ĺ�Ϊ 2. (-1 + 2 + 1 = 2).
*/

import java.util.Arrays;

public class ThreeSumClosest {
	public static void main(String[] args) {
		int[] nums = { -3, 0, 1, 2 };
		System.out.println(threeSumClosest(nums, 1));
	}

	//˼· : �������������,Ȼ�����ȷ��һ����,ͷβ˫ָ����Ծ��ȷ������������
	//		����һ��result����Ÿ�������Ĵ�,���targetֵ������֮�������ֱ�ӷ���
	//		�����ж�targetֵ������֮�͵Ĳ�ľ���ֵ���жϵ�ǰ�Ƿ���Ҫ����resultֵ
	//��� : ����ȡһ����,�����������ֱ�Ϊ��ǰ������������һ���������һ����,
	//		��ͷָ�����С��βָ�������ǰ����,������֮����target�����ֱ�ӷ���,
	//  	����������ĺ�С��target,��ͷָ���ƶ�,����βָ���ƶ�
	//		�ж�targetֵ������֮�͵Ĳ�ľ���ֵ���жϵ�ǰ�Ƿ���Ҫ����resultֵ
	public static int threeSumClosest(int[] nums, int target) {
		if (nums.length == 3) {
			return nums[0] + nums[1] + nums[2];
		}
		Arrays.sort(nums);
		int left;
		int right;
		int temp;
		int result = nums[0] + nums[1] + nums[2];
		for (int i = 0; i < nums.length; i++) {
			left = i + 1;
			right = nums.length - 1;
			while (left < right) {
				temp = (nums[i] + nums[left] + nums[right]);
				if (temp == target) {
					return temp;
				} else if (temp < target) {
					left++;
				} else {
					right--;
				}
				if (Math.abs(temp - target) < Math.abs(result - target)) {
					result = temp;
				}
			}
		}
		return result;
	}
}
