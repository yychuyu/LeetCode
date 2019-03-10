package Zeny.java; /**
 * Copyright (C), 2015-2019, XXX有限公司
 * FileName: Test334
 * Author:   xuyz
 * Date:     2019/3/2 20:24
 * Description: leetcode-334
 * History:
 * <author>          <time>          <version>          <desc>
 * 作者姓名           修改时间           版本号              描述
 */

/**
 * 〈一句话功能简述〉<br>
 * 〈leetcode-334〉
 *
 * @author xuyz
 * @create 2019/3/2
 * @since 1.0.0
 */
public class Solution {
    public static boolean increasingTriplet(int[] nums) {
        if(nums.length<3){
            return false;
        }
        boolean result = false;
        int left = Integer.MAX_VALUE;
        int middle = Integer.MAX_VALUE;
        for(int i = 0;i<nums.length;i++){
            if(left >= nums[i]){
                left = nums[i];
            }else if(middle >= nums[i]) {
                middle = nums[i];
            }else {
                result = true;
            }
        }
        return result;
    }

    public static void main(String[] args) {
        int[] test = new int[]{5,4,1,1,2,3};
        System.out.println(increasingTriplet(test));
    }
}
