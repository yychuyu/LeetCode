/**
 * Created by Json Wan on 2018/11/27.
 * Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

 Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

 Example 1:

 Given nums = [1,1,2],

 Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.

 It doesn't matter what you leave beyond the returned length.
 Example 2:

 Given nums = [0,0,1,1,1,2,2,3,3,4],

 Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.

 It doesn't matter what values are set beyond the returned length.
 Clarification:

 Confused why the returned value is an integer but your answer is an array?

 Note that the input array is passed in by reference, which means modification to the input array will be known to the caller as well.

 Internally you can think of this:

 // nums is passed in by reference. (i.e., without making a copy)
 int len = removeDuplicates(nums);

 // any modification to nums in your function would be known by the caller.
 // using the length returned by your function, it prints the first len elements.
 for (int i = 0; i < len; i++) {
 print(nums[i]);
 }
 思路：双下标，一个控制不重复的数，一个遍历即可。
 */
public class wanxu_pursue_0026 {

    /**
     *   解法已达最优
     */
    public int removeDuplicates(int[] nums) {
        if(nums.length==0)return 0;
        int i=0,j=0;
        int l=nums.length;
        while(j<l){
            if(nums[j]!=nums[i]){
                nums[++i]=nums[j];
            }
            j++;
        }
        return i+1;
    }

    public static void printArray(int[] nums){
        for(int x:nums){
            System.out.print(x+"");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        int[] arr=new int[]{0,0,1,1,1,2,2,3,3,4};
        System.out.println(new wanxu_pursue_0026().removeDuplicates(arr));
        printArray(arr);
    }

}
