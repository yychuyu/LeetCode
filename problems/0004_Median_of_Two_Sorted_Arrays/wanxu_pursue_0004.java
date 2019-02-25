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
 * ˼·���鲢���У����Ǹ��Ӷ�ΪO(n)
 * �ο�˼·��
 * ��λ���������ǿ��Խ�һ�������Ϊ�����ȳ�������
 * �������ת��Ϊ��
 * �����������зֱ�Ѱ��һ���ָ��i��j��ʹ�ã�
 * left_part                |        right_part
 * A[0], A[1], ..., A[i-1]  |  A[i], A[i+1], ..., A[m-1]
 * B[0], B[1], ..., B[j-1]  |  B[j], B[j+1], ..., B[n-1]
 * 1. len(left_part)=len(right_part)
 * 2. max(left_part)��min(right_part)
 * then we divide all elements in {A,B} into two parts with equal length, and one part is always greater than the other. Then
 * ��λ��=(max(left_part)+min(right_part))/2
 * ��Ҫ��֤������ת��Ϊ��
 * ��1��i+j=m-i+n-j
 * ��2��B[j-1]<=A[i]  and  A[i-1]<=B[j]
 * �ڱ�֤n>=m������£�
 * i ��ȡֵ��ΧΪ[0,m]
 * j = (m+n+1)/2-i
 * ���������ж��ֲ��ң�
 * i,j��ʼֵ�ֱ�ȡm,n����λ����
 * ����i,j�Ĳ��ϱ仯�����ܳ����������������
 * ��1��B[j-1]<=A[i]��A[i-1]<=B[j]
 * ��ʾĿ���Ѵ�ɣ�
 * ��2��B[j-1]>A[i]
 * ˵��i̫С��Ӧ����i��ǰ�ƣ�i����j�ͻ��С���Ⲩ�����Ὣi��j������
 * ��3��A[i-1]>B[j]
 * ˵��i̫��Ӧ����i����Ų��i��Сj�ͻ����ӣ��Ⲩ������Ȼ�ǽ�i��j������
 * ��ż����
 * ��m+nΪ����ʱ��
 * m=max(A[i-1],B[j-1])
 * ��m+nΪż��ʱ��
 * m=[max(A[i-1],B[j-1])+min(A[i],B[j])]/2
 * �߽紦��
 * ��ʵ���߽���������������Ƚϼ��ɣ�
 * ��1��
 * (j=0 or i = m or B[j-1]��A[i]) and
 * (i = 0 or j = n or A[i-1]��B[j])
 * ��ʾĿ���Ѵ�ɣ�
 * ��2��
 * j>0 and i<m and B[j-1] > A[i]
 * ˵��i̫С��Ӧ����i��ǰ�ƣ�i����j�ͻ��С���Ⲩ�����Ὣi��j������
 * ��3��
 * i>0 and j<n and A[i-1] > B[j]
 * ˵��i̫��Ӧ����i����Ų��i��Сj�ͻ����ӣ��Ⲩ������Ȼ�ǽ�i��j������
 */

public class wanxu_pursue_0004 {

    /**
     * ˼·���ڱȽϵ�ʱ��ͽ���߲��ֵ����ֵ���ұ߲��ֵ���Сֵ��¼�����������ǵȵ��������ȥ�жϴ�����������
     * ���⣺���õĸ�ֵ��ʵ�ɱ��Ǻܵ͵ģ�ֻҪ��������������˽�ԭ��֮��Ӧ�ÿ��Է���ʹ��
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
     * AC��0.75�����Ӷ�Ӧ���ǹ��ˣ��ֲ�ϸ�ڿ��Ż�
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
            //ż��
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
            //����
            if(i==0)
                return B[j-1];
            else if(j==0)
                return A[i-1];
            return max(A[i - 1], B[j - 1]);
        }
    }

    /**
     * ��֤nums1�ĳ���<=num2.length
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
