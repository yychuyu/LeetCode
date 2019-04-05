import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Author: Json Wan
 * Created at: 2019/3/2 13:48
 * Description:
 * 18. 4Sum
 * Medium
 * Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
 * Note:
 * The solution set must not contain duplicate quadruplets.
 * Example:
 * <p>
 * Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
 * A solution set is:
 * [
 * [-1,  0, 0, 1],
 * [-2, -1, 1, 2],
 * [-2,  0, 0, 2]
 * ]
 * 思路：与3Sum类似，思路也类似
 * 需要注意的点：
 * （1）去重复，循环内变下标，一方面考虑while而不是if，一方面需要时刻注意边界问题，防止越界后访问；
 **/
public class wanxu_pursue_0018 {

    //优化点1：將调用改为了循环；
    //优化点2：整个过程只新建了一次ArrayList，一次放四个数，避免了无效的循环添加，利用3层局部变量保存上下文信息，而不是递归再遍历的方式
    public List<List<Integer>> bestFourSum(int[] nums, int target) {
        List<List<Integer>> result = new ArrayList();
        Arrays.sort(nums);

        for(int i=0; i < nums.length - 3; i++) {
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3] > target)
                break;
            if(nums[i]+nums[nums.length-1]+nums[nums.length-2]+nums[nums.length-3]<target)
                continue;
            if(i>0 && nums[i-1]==nums[i]) continue;

            for(int j=i+1; j<nums.length-2; j++) {
                if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target)
                    break;
                if(nums[i]+nums[j]+nums[nums.length-1]+nums[nums.length-2]<target)
                    continue;
                if(j>i+1 && nums[j]==nums[j-1])
                    continue;

                int current = nums[i] + nums[j];

                int k = j+1;
                int l = nums.length-1;

                while(k<l) {
                    int sum = current + nums[k] + nums[l];
                    if(sum==target) {
                        result.add(Arrays.asList(new Integer[]{nums[i], nums[j], nums[k], nums[l]}));
                        while(k<l && nums[k]==nums[k+1]) {
                            k++;
                        }
                        while(k<l && nums[l]==nums[l-1]) {
                            l--;
                        }

                        k++;
                        l--;
                    } else if(sum<target) {
                        k++;
                    } else {
                        l--;
                    }
                }
            }
        }

        return result;
    }

    //AC,0.3193
    public List<List<Integer>> fourSum(int[] nums, int target) {
        Arrays.sort(nums);
        List<List<Integer>> result = new ArrayList<>();
        int l = nums.length;
        for (int i = 0; i < l - 3; i++) {
            //去除重复
            while (i < l - 3&&i != 0 && nums[i] == nums[i - 1]){
                i++;
            }
            if (i >= l - 3)
                break;
            List<List<Integer>> subResult = threeSum(nums, target - nums[i], i + 1);
            for (List<Integer> list : subResult) {
                list.add(nums[i]);
                result.add(list);
            }
        }
        return result;
    }

    private List<List<Integer>> twoSum(int[] nums, int target, int start) {
        List<List<Integer>> result = new ArrayList<>();
        int l = nums.length;
        int i = start, j = l - 1;
        while (i < j) {
            while (i<j&&i > start && nums[i] == nums[i - 1])
                i++;
            while (i<j&&j < l - 1 && nums[j] == nums[j + 1])
                j--;
            if(i>=j)
                break;
            int sum = nums[i] + nums[j];
            if (sum == target) {
                result.add(Arrays.asList(nums[i], nums[j]));
                i++;
                j--;
            } else if (sum < target) {
                i++;
            } else {
                j--;
            }
        }
        return result;
    }

    private List<List<Integer>> threeSum(int[] nums, int target, int start) {
        List<List<Integer>> result = new ArrayList<>();
        int l = nums.length;
        for (int i = start; i < l - 2; i++) {
            //去除重复
            while (i < l - 2&&i != start && nums[i] == nums[i - 1]) {
                i++;
            }
            if (i >= l - 2)
                break;
            List<List<Integer>> subResult = twoSum(nums, target - nums[i], i + 1);
            for (List<Integer> list : subResult) {
                list = new ArrayList<>(list);
                list.add(nums[i]);
                result.add(list);
            }
        }
        return result;
    }


    public static void main(String[] args) {
        wanxu_pursue_0018 instance = new wanxu_pursue_0018();
        System.out.println(instance.fourSum(new int[]{
                -4,0,-4,2,2,2,-2,-2}, 7));
        System.out.println(instance.fourSum(new int[]{
                0,0,4,-2,-3,-2,-2,-3}, -1));
        System.out.println(instance.fourSum(new int[]{
                -1, 2, 2, -5, 0, -1, 4}, 3));
        System.out.println(instance.fourSum(new int[]{0, 0, 0, 0}, 0));
        System.out.println(instance.fourSum(new int[]{1, 0, -1, 0, -2, 2}, 0));
    }
}
