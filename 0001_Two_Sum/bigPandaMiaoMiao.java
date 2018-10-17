/**
 * @author : bigPandaMiaoMiao
 * @date：2018-10-09
 * @jdk:1.8.0_151
 */

import java.util.Arrays;

/**************************************************************
 题目：
 Given an array of integers, return indices of the two numbers such that they add up to a specific target.

 You may assume that each input would have exactly one solution, and you may not use the same element twice.

 Example:
 Given nums = [2, 7, 11, 15], target = 9,

 Because nums[0] + nums[1] = 2 + 7 = 9,
 return [0, 1].
 释义：
 给定整型数组，返回两个数的下标，使得这两个数相加得到特定的值。
 假设每个给定的数组只能找到一组满足条件的结果，同时，不能使用同一个数两次。

 分析：
 题大意为，在一组数组中，找到两个数，使得这两个数的和等于特定值，并返回下标。可以从第一个数开始，循环与后面的每一个相加，与结果比较，比较成功则返回。
 例如，输入[1,7,11,15],目标值26，那么循环计算1+7,1+11,1+15，7+11,7+15......，直到得到目标值。
 ***************************************************************/

public class TwoSum {

    public void twoSum(int[] givenNums, int target, int[] result) {
        int length = givenNums.length;
        for (int i = 0; i < length; i++) {
            for (int j = i + 1; j < length; j++) {
                if (givenNums[i] + givenNums[j] == target) {
                    result[0] = i;
                    result[1] = j;
                    return;
                }
            }
        }
    }

    public static void main(String[] args) {
        int[] givenNums = {1, 7, 11, 15};
        int target = 26;
        int[] result = {-1, -1};
        TwoSum twoSum = new TwoSum();
        twoSum.twoSum(givenNums, target, result);

        System.out.println("给定的数组为：" + Arrays.toString(givenNums));
        System.out.println("特定目标值为：" + target);

        if (result[0] == -1) {
            System.out.println("没有符合的数据！");
        } else {
            System.out.println("返回的结果为：" + Arrays.toString(result));
        }

    }

}