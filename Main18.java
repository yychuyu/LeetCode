package com.company.page1;

import sun.security.util.Length;

import java.lang.annotation.Target;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * 4 sum
 */
public class Main18 {

    public static void main(String[] args){
        Main18 main = new Main18();
        List<List<Integer>> result = main.fourSum(new int[]{-3,-1,0,2,4,5},1);
        for (List<Integer> itemList:result){
            for (int item:itemList)
                System.out.print(item+" ");
            System.out.println();
        }
    }

    public List<List<Integer>> fourSum(int[] nums, int target) {
        //首先进行排序
        Arrays.sort(nums);
        int len = nums.length;
        List<List<Integer>>result = new ArrayList<>();
        for (int i = 0;i<len-3;i++){
            if (i==0||(i>0&&nums[i]!=nums[i-1])){
                int remain = target-nums[i];
                List<List<Integer>>threeSumList = threeSum(nums,remain,i+1,len);
                if (threeSumList.size()>0){
                    for (List<Integer> itemList:threeSumList){
                        itemList.add(0,nums[i]);
                    }
                    result.addAll(threeSumList);
                }
            }
        }
        return result;
    }

    /**
     * 计算3sum可能的情况
     * @param nums
     * @param target
     * @param start
     * @param length
     * @return
     */
    private List<List<Integer>> threeSum(int[] nums, int target, int start,int length) {
        List<List<Integer>> result = new ArrayList<>();
        for (int i = start;i<length-2;i++){
            if (i==start||(i>start&&nums[i]!=nums[i-1])){
                int remain = target-nums[i];
                int left = i+1;
                int right = length-1;
                while (left<right){
                    if (nums[left]+nums[right]==remain){
                        List<Integer> itemList = new ArrayList<>();
                        itemList.add(nums[i]);itemList.add(nums[left]);itemList.add(nums[right]);
                        result.add(itemList);
                        while (left<right&&nums[left]==nums[left+1])    left++;
                        while (left<right&&nums[right]==nums[right-1])  right--;
                        left++;right--;
                    }else if (nums[left]+nums[right]<remain)
                        left++;
                    else
                        right--;
                }
            }
        }
        return result;
    }

}
