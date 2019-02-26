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
    
    public static int removeElement(int[] nums, int val) {

        int len = 0;//用来记录最后得到的数组长度
        int j = 0;
        for(int i = 0;i<nums.length;i++) {
            if(nums[i] != val) {
                len++;//不相等，标记+1
                nums[j] = nums[i];//把不相等的数字往前移，从数组的第一位开始排
                j++;
            }
        }
        System.out.println(len);
        return len;
    }

    public static void main(String[] args) {

        int[] nums = {1,2,3,4};
        removeElement(nums,2);
    }

}
