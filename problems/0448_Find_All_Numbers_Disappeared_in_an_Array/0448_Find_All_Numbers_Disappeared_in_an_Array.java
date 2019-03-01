/*
给定一个范围在  1 ≤ a[i] ≤ n ( n = 数组大小 ) 的 整型数组，数组中的元素一些出现了两次，另一些只出现一次。

找到所有在 [1, n] 范围之间没有出现在数组中的数字。

您能在不使用额外空间且时间复杂度为O(n)的情况下完成这个任务吗? 你可以假定返回的数组不算在额外空间内。

示例:

输入:
[4,3,2,7,8,2,3,1]

输出:
[5,6]
*/

public class Solution {
	public List<Integer> findDisappearedNumbers(int[] nums) {
		List<Integer> list = new ArrayList<Integer>();
		//遍历数组，将数组上本该放置该元素的位置上置反
		for(int i = 0;i < nums.length;i++){
			int value = Math.abs(nums[i]) - 1;
			if(nums[value] > 0){
				nums[value] = -nums[value];
			}
		}
		//检查位置上为被置反的元素，将其添加到list中
		for(int i = 0;i < nums.length;i++){
			if(nums[i] > 0){
				list.add(i + 1);
			}
		}
		return list;
	}
}