import java.util.ArrayList;
import java.util.List;

/**
 * @Author 宋宗垚
 * @Date 2018/12/5 15:38
 * @Description 不同的二叉搜索树
 */
/*
给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？

示例:

输入: 3
输出: 5
解释:
给定 n = 3, 一共有 5 种不同结构的二叉搜索树:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
 */
public class Ashbringer {
//    public int numTrees(int n) {
//        /*
//        下面写的这个时间超过限制了
//         */
////       if(n == 0 || n == 1 ){
////           return 1;
////        }
////        int sum = 0;
////        for(int i = 1;i<=n;i++){
////            sum = sum + numTrees(i-1)* numTrees(n-i);
////        }
////        return sum;
//        if (n == 0)return 0;
//        if (n == 1) return 1;
//
//        int[] nums = new int[n+1];
//        nums[0] = 1; nums[1] = 1;
//
//        for (int i = 2; i <= n; i++) {
//            for (int j = 0; j < i; j++) {
//                nums[i] = nums[i] + nums[j] * nums[i-1-j];
//            }
//        }
//        return nums[n];
//
//
//
//    }

    public int numTrees(int n) {
        if (n==0 || n==1){
            return 1;
        }else{
            int[] data = new int[n+1];
            for (int i=0;i<=n;i++){
                if (i==0 ||i==1){
                    data[i]=1;
                }else {
                    for (int j = 0;j<i;j++){
                        data[i] = data[i] + data[j]*data[i-j-1];
                    }
                }
            }
            return data[n];
        }
    }
}
