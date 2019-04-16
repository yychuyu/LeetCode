package LeetCodePart3;


import java.util.Arrays;

/**
 * @author 刘云生
 * @date 2019/3/1320:56
 * 给定一个包含n个数的数组和一个目标值，找出其中的三个数，使得这三个数的和与目标值最接近，返回这三个数的和
 */
public class ThreeNumberSumClosest {
    public int threeSumClosest(int[] nums,int target){
        Arrays.sort(nums);
        int closestNum=nums[0]+nums[1]+nums[2];
        for (int i = 0; i <nums.length-2 ; i++) {
            int l = i + 1, r = nums.length - 1;
            while (l < r){
                int threeSum = nums[l] + nums[r] + nums[i];
                if (Math.abs(threeSum - target) < Math.abs(closestNum - target)) {
                    closestNum = threeSum;
                }
                if (threeSum > target) {
                    r--;
                } else if (threeSum < target) {
                    l++;
                } else {
                    // 如果已经等于target的话, 肯定是最接近的
                    return target;
                }

            }
        }
        return closestNum;
    }

    public static void main(String[] args) {
        ThreeNumberSumClosest threeNumberSumClosest=new ThreeNumberSumClosest();
        System.out.println(threeNumberSumClosest.threeSumClosest(new int[]{-1, 2, 1, -4},1));
    }
}
