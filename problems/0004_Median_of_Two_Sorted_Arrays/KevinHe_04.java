import java.util.ArrayList;

public class Main {

    public static void main(String[] args) {
        int[] nums1 = {1, 3};
        int[] nums2 = {2,};
        System.out.println(findMedianSortedArrays(nums1, nums2));
    }

//    public static double findMedianSortedArrays(int[] nums1, int[] nums2) {
//        int alllength = nums1.length + nums2.length;
//        boolean flag = false;//奇数置为false，偶数置为true
//        if (alllength % 2 == 0) flag = true;
//        int pos = alllength / 2 + 1;//计算中间元素位置
//        int i = 0, j = 0;//双指针
//        ArrayList<Integer> arrayList = new ArrayList<>();
//        while (i < nums1.length && j < nums2.length && arrayList.size() < pos) {
//            if (nums1[i] <= nums2[j]) {
//                arrayList.add(nums1[i]);
//                i++;
//            } else {
//                arrayList.add(nums2[j]);
//                j++;
//            }
//        }
//        while (i < nums1.length && arrayList.size() < pos) {
//            arrayList.add(nums1[i]);
//            i++;
//        }
//        while (j < nums2.length && arrayList.size() < pos) {
//            arrayList.add(nums2[j]);
//            j++;
//        }
//        if (pos == arrayList.size() && !flag) return arrayList.get(arrayList.size() - 1);
//        if (pos == arrayList.size() && flag)
//            return ((double) (arrayList.get(arrayList.size() - 1) + arrayList.get(arrayList.size() - 2))) / 2;
//        throw new IllegalArgumentException("没有中间元素");
//    }

    public static double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int index1 = 0;
        int index2 = 0;
        int med1 = 0;
        int med2 = 0;
        for (int i = 0; i <= (nums1.length + nums2.length) / 2; i++) {
            med1 = med2;
            if (index1 == nums1.length) {
                med2 = nums2[index2];
                index2++;
            } else if (index2 == nums2.length) {
                med2 = nums1[index1];
                index1 ++;
            } else if (nums1[index1] <= nums2[index2]) {
                med2 = nums1[index1];
                index1 ++;
            } else {
                med2 = nums2[index2];
                index2 ++;
            }
        }

        if ((nums1.length + nums2.length) % 2 == 0) {
            return (med1 + med2) / 2.0;
        }
        return med2;
    }
}
