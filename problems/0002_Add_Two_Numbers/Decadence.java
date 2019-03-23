import java.util.Arrays;

/**
 * Given an array of integers, return indices of the two numbers
 * such that they add up to a specific target.
 * You may assume that each input would have exactly one solution,
 * and you may not use the same element twice.

 * Example:
 * Given nums = [2, 7, 11, 15], target = 9,
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].

 **/
public class HowieLee {
    public static int[] twoSum(int[] numbers, int target) {
        for(int x=0; x<numbers.length; x++){
            for(int y = (x + 1); y < numbers.length - 1; y++){
                if(numbers[y] == (target - numbers[x])){
                    return new int[] {x,y};
                }
            }
        }
        return null;
    }

    public static void main(String[] args) {

        int[] numbers = {2, 7, 11, 15};
        int target = 9;
        int[] ints = twoSum(numbers, target);
        System.out.println(Arrays.toString(ints));
    }
}
