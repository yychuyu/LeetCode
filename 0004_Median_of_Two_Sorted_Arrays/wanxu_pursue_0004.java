import static java.lang.Double.max;
import static java.lang.Double.min;

/**
 * Created by Json Wan on 2018/12/4.
 * Description:
 * 4. Median of Two Sorted Arrays
 * Hard
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 * You may assume nums1 and nums2 cannot be both empty.
 * Example 1:
 * nums1 = [1, 3]
 * nums2 = [2]
 * The median is 2.0
 * Example 2:
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * The median is (2 + 3)/2 = 2.5
 * 思路：归并找中，但是复杂度为O(n)
 * 参考思路：
 * 中位数的作用是可以将一个数组分为两个等长子数组
 * 因此问题转化为：
 * 在两个数组中分别寻找一个分割点i与j，使得：
 * left_part                |        right_part
 * A[0], A[1], ..., A[i-1]  |  A[i], A[i+1], ..., A[m-1]
 * B[0], B[1], ..., B[j-1]  |  B[j], B[j+1], ..., B[n-1]
 * 1. len(left_part)=len(right_part)
 * 2. max(left_part)≤min(right_part)
 * then we divide all elements in {A,B} into two parts with equal length, and one part is always greater than the other. Then
 * 中位数=(max(left_part)+min(right_part))/2
 * 需要保证的条件转化为：
 * （1）i+j=m-i+n-j
 * （2）B[j-1]<=A[i]  and  A[i-1]<=B[j]
 * 在保证n>=m的情况下：
 * i 的取值范围为[0,m]
 * j = (m+n+1)/2-i
 * 接下来进行二分查找：
 * i,j初始值分别取m,n的中位数；
 * 随着i,j的不断变化，可能出现以下三种情况：
 * （1）B[j-1]<=A[i]，A[i-1]<=B[j]
 * 表示目标已达成；
 * （2）B[j-1]>A[i]
 * 说明i太小，应当将i往前推，i增加j就会减小，这波操作会将i与j拉近；
 * （3）A[i-1]>B[j]
 * 说明i太大，应当将i往后挪，i减小j就会增加，这波操作依然是将i与j拉近。
 * 奇偶处理：
 * 当m+n为奇数时：
 * m=max(A[i-1],B[j-1])
 * 当m+n为偶数时：
 * m=[max(A[i-1],B[j-1])+min(A[i],B[j])]/2
 * 边界处理：
 * 其实，边界的情况根本就无需比较即可：
 * （1）
 * (j=0 or i = m or B[j-1]≤A[i]) and
 * (i = 0 or j = n or A[i-1]≤B[j])
 * 表示目标已达成；
 * （2）
 * j>0 and i<m and B[j-1] > A[i]
 * 说明i太小，应当将i往前推，i增加j就会减小，这波操作会将i与j拉近；
 * （3）
 * i>0 and j<n and A[i-1] > B[j]
 * 说明i太大，应当将i往后挪，i减小j就会增加，这波操作依然是将i与j拉近。
 */

public class wanxu_pursue_0004 {

    /**
     * 思路：在比较的时候就将左边部分的最大值与右边部分的最小值记录下来，而不是等到最后了再去判断存在性重新找
     * 另外：引用的赋值其实成本是很低的，只要不是深拷贝，所以了解原理之后应该可以放心使用
     * @param nums1
     * @param nums2
     * @return
     */
    public double bestFindMedianSortedArrays(int[] nums1, int[] nums2) {
        int[] A, B;
        int m = nums1.length;
        int n = nums2.length;
        if (m > n) {
            m = m ^ n;
            n = m ^ n;
            m = m ^ n;
            A = nums2;
            B = nums1;
        } else {
            A = nums1;
            B = nums2;
        }


        int iMin = 0, iMax = m, half = (m + n + 1) / 2;
        int i, j, maxL, minR;
        while (iMin <= iMax) {
            i = (iMin + iMax) / 2;
            j = half - i;
            if (i < iMax && B[j - 1] > A[i]) {
                iMin = i + 1;
            } else if (i > iMin && A[i - 1] > B[j]) {
                iMax = i - 1;
            } else {
                maxL = 0;
                if (i == 0) {
                    maxL = B[j - 1];
                } else if (j == 0) {
                    maxL = A[i - 1];
                } else {
                    maxL = Math.max(A[i - 1], B[j - 1]);
                }
                if ((m + n) % 2 == 1) {
                    return maxL;
                }

                minR = 0;
                if (i == m) {
                    minR = B[j];
                } else if (j == n) {
                    minR = A[i];
                } else {
                    minR = Math.min(B[j], A[i]);
                }

                return (maxL + minR) / 2.0;
            }
        }

        return 0.0;
    }
    /**
     * AC，0.75，复杂度应该是够了，局部细节可优化
     * @param A
     * @param B
     * @return
     */
    public double findMedianSortedArraysImp(int[] A, int[] B) {
        int m = A.length;
        int n = B.length;
        if(m==0){
            if(n%2==0){
                return (B[n/2-1]+B[n/2])/2;
            }else{
                return B[n/2];
            }
        }
        int l = 0, r = m;
        int i = m / 2, j = (m + n + 1) / 2 - i;
        while (!((j == 0 || i == m || B[j - 1] <= A[i]) && (i == 0 || j == n || A[i - 1] <= B[j]))) {
            if (j > 0 && i < m && B[j - 1] > A[i]) {
                if (i < r) {
                    l = i + 1;
                } else {
                    break;
                }
            } else if (i > 0 && j < n && A[i - 1] > B[j]) {
                if (i > l) {
                    r = i - 1;
                } else {
                    break;
                }
            }
            i = (l + r) / 2;
            j = (m + n + 1) / 2 - i;
        }
        if ((m + n) % 2 == 0) {
            //偶数
            if(i==0){
                if(j==n){
                    return (B[j-1]+A[i])/2.0;
                }else{
                    return (B[j-1]+min(A[i],B[j]))/2.0;
                }
            }else if(j==0){
                if(i==m){
                    return (A[i-1]+B[j])/2.0;
                }else{
                    return (A[i-1]+min(A[i],B[j]))/2.0;
                }
            }else if(i==m){
                return (max(A[i-1],B[j-1])+B[j])/2.0;
            }else if(j==n){
                return (max(A[i-1],B[j-1])+A[i])/2.0;
            }else {
                return (max(A[i - 1], B[j - 1]) + min(A[i], B[j])) / 2.0;
            }
        } else {
            //奇数
            if(i==0)
                return B[j-1];
            else if(j==0)
                return A[i-1];
            return max(A[i - 1], B[j - 1]);
        }
    }

    /**
     * 保证nums1的长度<=num2.length
     *
     * @param nums1
     * @param nums2
     * @return
     */
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        if (nums1.length <= nums2.length)
            return findMedianSortedArraysImp(nums1, nums2);
        else
            return findMedianSortedArraysImp(nums2, nums1);
    }

    public static void main(String[] args) {
//        int[] nums1 = new int[]{1, 2};
//        int[] nums2 = new int[]{3, 4};
//        int[] nums1 = new int[]{};
//        int[] nums2 = new int[]{3, 4};
//        int[] nums1 = new int[]{1,3,5};
//        int[] nums2 = new int[]{3, 4};
        int[] nums1 = new int[]{1,5};
        int[] nums2 = new int[]{3, 4,6};
        System.out.println(new wanxu_pursue_0004().findMedianSortedArrays(nums1, nums2));
    }
}
