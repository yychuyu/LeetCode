package Day1;

/*
给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。

示例 1:

给定数组 nums = [1,1,2],

函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。

你不需要考虑数组中超出新长度后面的元素。
示例 2:

给定 nums = [0,0,1,1,1,2,2,3,3,4],

函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。

你不需要考虑数组中超出新长度后面的元素。

*/


/**
 * @author THY
 * @date 2018/10/9
 */
public class YuanCome {
    //题意不能设置set保存数组，仅能在原数组进行操作
    //原数组为排序数组! 可以忽略后续出现重复数字问题
    private static int removeDuplicates(int[] nums) {
        if(nums.length == 0) {
            return 0;
        }
        int i = 0;
        for (int j = 1; j < nums.length; j++) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }

    //自定义测试用例
    public static void main(String[] args) {
        int[] nums = new int[]{1,2,5,5,6,6,6,7};
        System.out.println(removeDuplicates(nums));
    }

    //LeetCode最优解
    // class Solution {
    //     public int removeDuplicates(int[] nums) {
    //         if (nums.length == 0)
    //             return 0;
    //         int i = 0, j = i + 1;
    //         while (j != nums.length) {
    //             if (nums[i] != nums[j]) {
    //                 i++;
    //                 if (i != j) {
    //                     nums[i] = nums[j];
    //                 }
    //             }
    //             j++;
    //         }
    //         return i + 1;
    //     }
    // }
}
