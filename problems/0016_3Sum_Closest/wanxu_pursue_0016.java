import java.util.Arrays;

/**
 * @Author: Json Wan
 * Created at: 2019/2/24.
 * Description:
 * Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
Example:
Given array nums = [-1, 2, 1, -4], and target = 1.
The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 思路：解空间为Cn3，关键在于如何以低于n3方的代价找出解；
 n2logn的思路：
 （1）nlogn排序
 （2）遍历nums[i]，在剩余数中找最接近target-nums[i]的两个数
 （3）遍历剩余的数nums[j]，再在剩余的数中找最接近target-nums[i]-nums[j]的一个数
 习得：
 （1）从有序数组中找出和为定值的两个数的最优时间复杂度是O(n)而不是O(nlogn)，方法是首尾端逐个排除法；
 （2）从数组中找出和为定值的两个数的最优时间复杂度是O(nlogn)的原因是让数组变得有序需要O(nlogn)的时间。
 */
public class wanxu_pursue_0016 {

    //与best思路差不多，我觉得不是最优，但是时间复杂度似乎是n2，为什么呢？
    //实际上是最优，因为从有序数组中找出和为定值的两个数的最优时间复杂度是O(n)而不是O(nlogn)，方法是首尾端逐个排除法，每排除一次记录一次最短距离
    public int best2ThreeSumClosest(int[] nums, int target) {
        int diff = Integer.MAX_VALUE, result = 0;
        Arrays.sort(nums);
        for (int i = 0; i < nums.length - 2; i++) {
            int left = i + 1, right = nums.length - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == target) {
                    return sum;
                }
                if (diff > Math.abs(target - sum)) {
                    diff = Math.abs(target - sum);
                    result = sum;
                }
                if (sum > target) {
                    right--;
                } else {
                    left++;
                }
            }
        }
        return result;
    }
    //其实这个解法应该不是最优，最底层用的遍历不是二分，在数据量大的时候性能应该会崩
    public int bestThreeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int res = nums[0] + nums[1] + nums[2];
        for(int i=0;i<nums.length;i++){
            //优化细节1：同样的数字避免重复搜索
            if(i>0 && nums[i]==nums[i-1]) continue;

            int temp = twoSum(nums, target, nums[i], i+1, res);
            if(temp==target) return target;

            if(Math.abs(res-target)>Math.abs(temp-target)) res = temp;
        }
        return res;
    }

    private int twoSum(int[]nums, int target, int x1, int start, int res){
        int end = nums.length-1;
        while(start<end){
            int x2 = nums[start];
            int x3 = nums[end];
            int sum = x1+x2+x3;
            if(sum==target) return target;
            if(sum>target) end--;
            else start++;
            if(Math.abs(sum-target)<Math.abs(res-target)) res = sum;
        }
        return res;
    }

    //AC，0.8409，算法应该是最优时间复杂度了//其实不是，最优复杂度是O(n2)
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int distance=Integer.MAX_VALUE;
        int l=nums.length;
        for(int i=0;i<l-2;i++){
            int d=twoSumClosest(nums,i+1,target-nums[i]);
            if(Math.abs(d)<Math.abs(distance)){
                distance=d;
                if(distance==0){
                    break;
                }
            }
        }
        return target-distance;
    }

    private int twoSumClosest(int[] nums,int start, int target) {
        int distance=Integer.MAX_VALUE;
        int l=nums.length;
        for(int i=start;i<l-1;i++){
            int d=oneSumClosest(nums,i+1,target-nums[i]);
            if(Math.abs(d)<Math.abs(distance)){
                distance=d;
                if(distance==0){
                    break;
                }
            }
        }
        return distance;
    }
    //可用二分查找优化
    private int oneSumClosest(int[] nums,int start, int target) {
        int distance=Integer.MAX_VALUE;
        int len=nums.length;
        //二分的方式
        int l=start,r=len-1;
        int m;
        while(l<r){
            m=l+(r-l)/2;
            if(nums[m]==target){
                return 0;
            }else if(nums[m]<target){
                l=m+1;
            }else{
                r=m-1;
            }
        }
        distance=target-nums[l];
        if(l-1>=start){
            if(Math.abs(target-nums[l-1])<Math.abs(distance)){
                distance=target-nums[l-1];
            }
        }
        if(l+1<=len-1){
            if(Math.abs(target-nums[l+1])<Math.abs(distance)){
                distance=target-nums[l+1];
            }
        }
//        遍历的方式
//        for(int i=start;i<len;i++){
//            int d=target-nums[i];
//            if(Math.abs(d)<Math.abs(distance)){
//                distance=d;
//                if(distance==0){
//                    break;
//                }
//            }
//        }
        return distance;
    }

    public static void main(String[] args) {
        wanxu_pursue_0016 instance=new wanxu_pursue_0016();
        System.out.println(instance.threeSumClosest(new int[]{-1, 2, 1, -4},1)==2);
        System.out.println(instance.threeSumClosest(new int[]{-1, 2, 1, -4,1,2},1)==1);
        System.out.println(instance.threeSumClosest(new int[]{1,2,3,4,5,6,7,8,9},10)==10);
    }
}
