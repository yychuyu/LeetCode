package test;

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

    public static int missingNumber(int[] nums) {

        int sum = 0;
        for (int elem : nums) {
            sum += elem;
        }
        return ((1 + nums.length) * nums.length / 2) - sum;
    }

    public static void main(String[] args) {

        int[] nums = {1,2,3,4};
        missingNumber(nums);
    }

}
