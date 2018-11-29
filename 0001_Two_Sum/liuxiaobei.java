package test;

/**
 * Created with IntelliJ IDEA.
 * Description:
 *
 * @author: liuxiaobei
 * @Date: 2018-11-06
 * @Time: 23:03
 */
public class liuxiaobei {


    public static int[] twoSum(int[] nums, int target) {

        for(int i=0;i<nums.length;i++) {

            for(int j = i + 1;j<nums.length;j++) {

                if(nums[i] + nums[j] == target) {

                    return new int[]{i,j};
                }
            }
        }

        return null;
    }

    public static void main(String[] args) {

        int[] result = twoSum(new int[]{2, 7, 11, 15},9);
        System.out.println(result[0]+""+result[1]);
    }

}
