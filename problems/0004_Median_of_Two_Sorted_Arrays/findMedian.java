package LeetCodePart1;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * @author 刘云生
 * @date 2019/3/817:06
 * 在给定两个数组的情况下（可以假设两个数组不会同时为空），找出这两个数组的中位数
 * 要求：算法的时间复杂度为 O(log(m + n))
 * 示例 1: *
 * nums1 = [1, 3]
 * nums2 = [2] *
 * 则中位数是 2.0
 * 示例 2: *
 * nums1 = [1, 2]
 * nums2 = [3, 4] *
 * 则中位数是 (2 + 3)/2 = 2.5
 */
public class findMedian {
    public double Median(int[] a,int[] b) {

        double median=0;
        if (a==null&&b==null){
            System.out.println("两个数组不能同时为空，请重新输入!");
        }else {
            List<Integer> list=new ArrayList<>();
            if (b!=null){
                for (int i = 0; i < b.length; i++) {
                    list.add(b[i]);
                }
            }
            if (a!=null){
                for (int i = 0; i < a.length; i++) {
                    list.add(a[i]);
                }
            }
            Collections.sort(list);
            int num=list.size();
            if (num%2==0){
                median=(list.get(num/2)+list.get(num/2-1))/2;
            }else {
                median=list.get(num/2);
            }
        }
        return median;
    }

    public static void main(String[] args) {
        findMedian findMedian=new findMedian();
        System.out.println((double)3/2);
    }
}
