package test;

import org.junit.Test;

import java.util.ArrayList;
import java.util.List;

/**
 * Created with IntelliJ IDEA.
 * Description:
 *
 * @author: liuxiaobei
 * @Date: 2018-11-06
 * @Time: 23:03
 */
public class liuxiaobei {

    /**
     *
     * 给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。

     你可以假设数组是非空的，并且给定的数组总是存在众数。
     * */
    public static int majorityElement(int[] nums) {

        int maj = nums[0];
        int count = 1;
        for (int num : nums) {
            if (maj == num) {
                count++;
            } else {
                count--;
                if (count == 0) {
                    maj = num;
                    count = 1;
                }
            }
        }
        return maj;
    }

    public static void main(String[] args) {

        int[] nums = {1,2,3,4};
        majorityElement(nums);
    }

}
