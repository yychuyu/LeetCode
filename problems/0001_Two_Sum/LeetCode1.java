import java.util.Arrays;
//https://blog.csdn.net/Victordas/article/details/83958474
//给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。
//你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。
//给定 nums = [2, 7, 11, 15], target = 9
//因为 nums[0] + nums[1] = 2 + 7 = 9
//所以返回 [0, 1]

public class LeetCode1 {
	
	int nums[] = {2, 7, 11, 15};
	
	
	public static void main(String[] args) {
		LeetCode1 L1 = new LeetCode1();
		System.out.println(Arrays.toString(L1.twoSum(L1.nums , 9)));
		System.out.println(Arrays.toString(L1.nums));
	}

	public int[] twoSum(int[] nums, int target) {
		for(int i=0; i<nums.length; i++){
			for(int j = i+1; j<nums.length;j++){
				int sum = nums[i] + nums[j];
				if(sum == target){
					return new int[] {i,j};
				}
			}
		}
		throw new IllegalArgumentException("No two sum");
	}
}


