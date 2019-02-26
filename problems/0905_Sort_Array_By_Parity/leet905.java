/**
 * 给定一个非负整数数组 A，返回一个由 A 的所有偶数元素组成的数组，后面跟 A 的所有奇数元素。
 * 你可以返回满足此条件的任何数组作为答案。
 * 输入：[3,1,2,4]
 * 输出：[2,4,3,1]
 * 输出 [4,2,3,1]，[2,4,1,3] 和 [4,2,1,3] 也会被接受。
 * */
public class leet905 {
    public static void main(String[] args) {
        int[] A = {3,1,2,4};
        int[] B = leet905.sortArrayByParity(A);
        System.out.print("["+B[0]);
        for (int b=1;b<B.length;b++) {
            System.out.print(","+B[b]);
        }
        System.out.print("]");
    }
    public static int[] sortArrayByParity(int[] A) {

        int j=0;
        int[] temp = new int[A.length];
        for (int i=A.length-1;i>=0;i--){
            if (A[i]%2 == 0){
                temp[j]=A[i];
                j++;
            }
        }
        for (int i=A.length-1;i>=0;i--){
            if (A[i]%2 != 0){
                temp[j]=A[i];
                j++;
            }
        }
        return temp;
    }
}
