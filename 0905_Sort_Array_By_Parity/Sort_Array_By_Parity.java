	/**
     * * @Description
     * *给定一个非负整数数组 A，返回一个由 A 的所有偶数元素组成的数组，后面跟 A 的所有奇数元素。
        你可以返回满足此条件的任何数组作为答案。
     * * @Author 22k
     * * @Email 8430177@qq.com
     * * @Date 2018-11-13 17:24
     **/
class Solution {
    public int[] sortArrayByParity(int[] A) {
        int[] B=new int[A.length];
        int x =0;//偶数的索引
        int y =A.length-1; //奇数的索引
        for (int i=0;i<A.length&&A.length>=1&&A.length<=5000;i++){
            if (A[i]%2==0&&A[i]>=0&&A[i]<=5000)
                B[x++]=A[i];
            else
                B[y--]=A[i];
        }
        return B;
    }
}