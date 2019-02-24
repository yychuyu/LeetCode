package algorithm._027_removeElement;
/*
给定一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，返回移除后数组的新长度。
不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
示例 1:
	给定 nums = [3,2,2,3], val = 3,
	函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。
	你不需要考虑数组中超出新长度后面的元素。
示例 2:
	给定 nums = [0,1,2,2,3,0,4,2], val = 2,
	函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。
	注意这五个元素可为任意顺序。
	你不需要考虑数组中超出新长度后面的元素。
说明:
	为什么返回数值是整数，但输出的答案是数组呢?
	请注意，输入数组是以“引用”方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。
	你可以想象内部操作如下:
		// nums 是以“引用”方式传递的。也就是说，不对实参作任何拷贝
		int len = removeElement(nums, val);
		// 在函数里修改输入数组对于调用者是可见的。
		// 根据你的函数返回的长度, 它会打印出数组中该长度范围内的所有元素。
		for (int i = 0; i < len; i++) {
    		print(nums[i]);
		}
*/
==
public class RemoveElement {
	public static void main(String[] args) {
		System.out.println(removeElement(new int[] { 3, 2, 2, 3 }, 3));
	}

	//思路 : 定义一个数来记录删除数字的个数(该数同时也表示元素需要移动的位数),
	//		因为要做原数组进行修改,所有将原数组看做两个数组
	//		遍历该数组,当遇到的值为val时,即不对该数进行拷贝,其余都进行拷贝
	//解法 : 定义一个move用来记录删除数字的个数(该数同时也表示元素需要移动的位数),
	//		40-46行实现了这让该数组进行原地拷贝,而遇到的值等于val时,则不对该数进行拷贝,
	//		此后拷贝的元素索引则需要其向前移动move个单位,而修改后的数组长度即为原数组长度减去move
	public static int removeElement(int[] nums, int val) {
		int move = 0;
		for (int i = 0; i < nums.length; i++) {
			if (nums[i] == val) {
				move++;
				continue;
			}
			nums[i - move] = nums[i];
		}
		return nums.length - move;
	}
}
