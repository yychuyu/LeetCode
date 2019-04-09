package LeetCodePart3;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

/**
 * @author 刘云生
 * @date 2019/3/1320:03
 * 给定一个整数数组，找出所有的满足三个数之和为0的三元组，并输出
 */
public class ThreeNumberSum {
    public List<List<Integer>> treeSum(int[] nums){
        List<Integer> integers=new ArrayList<>();
        for (int i = 0; i <nums.length ; i++) {
            integers.add(nums[i]);
        }
        List<List<Integer>> lists=new ArrayList<>();
        for (int i = 0; i <nums.length-1 ; i++) {
            for (int j = nums.length - 1; j > i; j--) {
                int sum = nums[i] + nums[j];
                List<Integer> integer=integers.subList(i+1,j);
                if (integer.contains(-sum)) {
                    List<Integer> list = new ArrayList<>();
                    list.add(nums[i]);
                    list.add(nums[j]);
                    list.add(-sum);
                    Collections.sort(list);
                    if (!lists.contains(list)){
                        lists.add(list);
                    }
                }
            }
        }
        return lists;
    }

    public static void main(String[] args) {
        ThreeNumberSum threeNumberSum=new ThreeNumberSum();
        System.out.println(threeNumberSum.treeSum(new int[]{0, 0, 0, 0}));
    }
}
