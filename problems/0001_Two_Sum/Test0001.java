package cn.plummy;

/**
 * ����һ���������� nums ��һ��Ŀ��ֵ target�������ڸ��������ҳ���ΪĿ��ֵ�� ���� ������
 * ����Լ���ÿ������ֻ���Ӧһ���𰸡����ǣ��㲻���ظ��������������ͬ����Ԫ�ء�
 * ʾ��:
 * ���� nums = [2, 7, 11, 15], target = 9
 * ��Ϊ nums[0] + nums[1] = 2 + 7 = 9 ���Է��� [0, 1]
 * @author lilin
 */
public class Test0001 {
	public static void main(String[] args) {
		int [] res = new Test0001().twoSum(new int[]{2, 7, 11, 15}, 9);
		for (int temp : res) {
			System.out.print(temp + "\t");
		}
	}
	
	/**
	 * ��һ�����κͺ���ÿ�������,������͵���target,�ͷ����������������е��±�ֵ
	 * @param nums
	 * @param target
	 * @return
	 */
	public int[] twoSum(int[] nums, int target) {
		for (int i = 0; i <= nums.length - 1; i++) {
			for (int j = i + 1; j <= nums.length; j++) {
				if (nums[i] + nums[j] == target) {
					return new int[]{i,j};
				}
			}
		}
		return null;
	}
}
