package sorting.medium.quicksort;

/**
 * 给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

 此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
    LeetCode 075 颜色分类
 注意:
 不能使用代码库中的排序函数来解决这道题。
 * */

public class SortedColor {
    public  void swap(int nums[], int i, int j){
        int tmp = nums[i];
        nums[i]=nums[j];
        nums[j]=tmp;
    }

    public  void sortColors(int[] nums) {
        if(nums == null || nums.length==0)
            return;

        int notred=0;
        int notblue=nums.length-1;

        while (notred<nums.length&&nums[notred]==0)
            notred++;

        while (notblue>=0&&nums[notblue]==2)
            notblue--;

        int i=notred;
        while (i<=notblue){
            if (nums[i]==0) {
                swap(nums,i,notred);
                notred++;
                i++;
            }else if (nums[i]==2) {
                swap(nums,i,notblue);
                notblue--;
            }else
                i++;
        }
    }
}


