import java.util.*;

public class nicefuture
{
    public static void main(String [] args) {
        nicefuture init = new nicefuture();
        int [] nums1 = {1, 3, 5, 7, 9};
        int [] nums2 = {2, 4, 6, 8};

        System.out.println(init.findMedianSortedArrays(nums1, nums2));
    }

    //-----------------------------------------------------------------

    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        ArrayList<Integer> list = new ArrayList<Integer>();
        for (int i : nums1) {
            list.add(i);
        }
        for (int i : nums2) {
            list.add(i);
        }
        Collections.sort(list);
        int length = nums1.length+nums2.length;
        if (length % 2 == 0) {
            return (list.get(length/2-1)+list.get(length/2)) / 2.0;
        } else {
            return list.get(length/2);
        }
    }
    //------------------------------------------------------------------
}
