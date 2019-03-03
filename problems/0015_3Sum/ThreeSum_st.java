package algorithm._015_threeSum;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
/*
����һ������ n ������������ nums���ж� nums ���Ƿ��������Ԫ�� a��b��c ��ʹ�� a + b + c = 0 ��
�ҳ��������������Ҳ��ظ�����Ԫ�顣
ע�⣺���в����԰����ظ�����Ԫ�顣
	����, �������� nums = [-1, 0, 1, 2, -1, -4]��
	����Ҫ�����Ԫ�鼯��Ϊ��
	[
  		[-1, 0, 1],
  		[-1, -1, 2]
	]
*/

public class ThreeSum {
	public static void main(String[] args) {
		int[] nums = { -4, -1, -1, 0, 1, 2 };
		List<List<Integer>> list = threeSum(nums);
		for (List<Integer> l : list) {
			System.out.println(l);
		}
	}

	//˼· : �������������,Ȼ�����ȷ��һ����,ͷβ˫ָ����Ծ��ȷ������������
	//		��Ҫע����ĿҪ�󲻵ó����ظ��Ĵ�,������set�����ų��ظ���,Ҳ���Լ������ж�
	//��� : ����ȡһ����,�����������ֱ�Ϊ��ǰ������������һ���������һ����,
	//		��ͷָ�����С��βָ�������ǰ����,����������ĺ�С��0,��ͷָ���ƶ�,����βָ���ƶ�
	//  	�������������ϸ��������������� (���ó����ظ��Ĵ�)
	//		�������ʱ,��ͷָ���ƶ�,��ʱ��Ҫע��ͷָ�������֮ǰ�����Ƿ����,
	//		Ҫʹ�������ж� (���ó����ظ���)
	public static List<List<Integer>> threeSum(int[] nums) {
		List<List<Integer>> result = new ArrayList<List<Integer>>();
		Arrays.sort(nums);
		int left;
		int right;
		int temp;
		for (int i = 0; i < nums.length; i++) {
			if (i > 0 && nums[i] == nums[i - 1]) {
				continue;
			}
			left = i + 1;
			right = nums.length - 1;
			while (left < right) {
				temp = (nums[i] + nums[left] + nums[right]);
				if (temp == 0) {
					List<Integer> list = new ArrayList<Integer>();
					list.add(nums[i]);
					list.add(nums[left]);
					list.add(nums[right]);
					result.add(list);
					left++;
					while (left < right && nums[left] == nums[left - 1]) {
						left++;
					}
				} else if (temp < 0) {
					left++;
				} else {
					right--;
				}
			}
		}
		return result;
	}

}
