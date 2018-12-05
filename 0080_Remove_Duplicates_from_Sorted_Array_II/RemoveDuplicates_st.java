package algorithm._080_removeDuplicates;
/*
给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素最多出现两次，返回移除后数组的新长度。
不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
示例 1:
	给定 nums = [1,1,1,2,2,3],
	函数应返回新长度 length = 5, 并且原数组的前五个元素被修改为 1, 1, 2, 2, 3 。
	你不需要考虑数组中超出新长度后面的元素。
示例 2:
	给定 nums = [0,0,1,1,1,1,2,3,3],
	函数应返回新长度 length = 7, 并且原数组的前五个元素被修改为 0, 0, 1, 1, 2, 3, 3 。
	你不需要考虑数组中超出新长度后面的元素。
说明:
	为什么返回数值是整数，但输出的答案是数组呢?
	请注意，输入数组是以“引用”方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。
	你可以想象内部操作如下:
		// nums 是以“引用”方式传递的。也就是说，不对实参做任何拷贝
		int len = removeDuplicates(nums);
		// 在函数里修改输入数组对于调用者是可见的。
		// 根据你的函数返回的长度, 它会打印出数组中该长度范围内的所有元素。
		for (int i = 0; i < len; i++) {
    		print(nums[i]);
		}
*/

public class RemoveDuplicates {
	public static void main(String[] args) {
		int[] nums = {0,0,1,1,1,1,2,3,3};
		System.out.println(removeDuplicates(nums));
	}
	
	//思路 : 因为题目要求在原数组上进行删除,且又因为是排序好的数组,
	//  	所有可以把一个数组当做两个数组进行操作,一个进行遍历,另一个即为删除后的数组
	//		而两个数组的长度相差了删除了元素的个数
	//解法 : 定义一个delete来记录删除了的元素个数,以及isTwoAppear来判断该元素是否需要进行删除
	//		判断目标数组的最后一个元素与当前遍历的元素是否相等,相等则再判断isTwoAppear是否为true
	//		如果为true则delete加1,否则另isTwoAppear变为true确保如果下一个数相等的话则进行删除
	//		除了当前遍历的数需要删除的情况,其他时候都需要确保目标数组元素的更新
	//		即要令nums[i - delete] = nums[i]
	public static int removeDuplicates(int[] nums) {
		int delete = 0;
		boolean isTwoAppear = false;
		for (int i = 1; i < nums.length; i++) {
			if (nums[i] == nums[i - 1 - delete]) {
				if (isTwoAppear) {
					delete++;
				}
				isTwoAppear = true;
			} else {
				isTwoAppear = false;
			}
			nums[i - delete] = nums[i];
		}
		return nums.length - delete;
	}
}
