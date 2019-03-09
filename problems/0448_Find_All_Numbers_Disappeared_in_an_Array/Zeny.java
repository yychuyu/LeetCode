import static java.lang.Math.abs;

/**
 * 〈一句话功能简述〉<br>
 * 〈LeetCode-448〉
 *
 * @author xuyz
 * @create 2019/3/3
 * @since 1.0.0
 */
public class Solution {

    public static List<Integer> findDisappearedNumbers(int[] nums) {
        List<Integer> result = new ArrayList<>();
        for(int i= 0;i<nums.length;i++){
            nums[abs(nums[i])-1] = -abs(nums[abs(nums[i])-1]);
        }
        for(int i=0;i<nums.length;i++){
            if(nums[i]>0){
                result.add(i+1);
            }
        }
        return result;
    }

    public static void main(String[] args) {
        int[] test = new int[]{4,3,2,7,8,2,3,1};
        System.out.println(findDisappearedNumbers(test));
    }
}
