package LeetCodePart1;

import java.util.HashMap;
import java.util.Map;

/**
 * @author 刘云生
 * @date 2019/2/2719:26
 *给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
 * 给定 nums = [2, 7, 11, 15], target = 9
 * 因为 nums[0] + nums[1] = 2 + 7 = 9
 * 所以返回 [0, 1]
 */
public class twoSumSolution {
    //     方法1：暴力解决
    public int[] twoSum1(int[] nums,int target){
        for (int i = 0; i <nums.length ; i++) {
            if (i!=0){
                for (int j = 0; j <i ; j++) {
                    if (nums[i]+nums[j]==target){
                        return new int[] {j,i};
                    }
                }
            }
        }
        throw new IllegalArgumentException("No two sum solution");
    }
    //   方法2：两遍遍历使用哈希表
    public int[] twoSum2(int[] nums,int target){
        Map<Integer,Integer> numsMap=new HashMap<>();
        for (int i = 0; i <nums.length ; i++) {
            numsMap.put(nums[i],i);
        }
        for (int i = 0; i <numsMap.size() ; i++) {
            int number=target-nums[i];
            if (numsMap.containsKey(number)&&numsMap.get(number)!=i){
                return new int[] {i,numsMap.get(number)};
            }
        }
        throw new IllegalArgumentException("No two sum solution");
    }
}
