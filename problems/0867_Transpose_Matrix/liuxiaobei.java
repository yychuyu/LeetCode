package test;

import org.junit.Test;

/**
 * Created with IntelliJ IDEA.
 * Description:
 *
 * @author: liuxiaobei
 * @Date: 2018-11-06
 * @Time: 23:03
 */
public class liuxiaobei {

    /**
     *
     * 给定一个矩阵 A， 返回 A 的转置矩阵。
     *
     * 矩阵的转置是指将矩阵的主对角线翻转，交换矩阵的行索引与列索引。
     *
     *
     *
     * 示例 1：
     *
     * 输入：[[1,2,3],[4,5,6],[7,8,9]]
     * 输出：[[1,4,7],[2,5,8],[3,6,9]]
     * 示例 2：
     *
     * 输入：[[1,2,3],[4,5,6]]
     * 输出：[[1,4],[2,5],[3,6]]
     * */
    private static int[][] reverseArray(int[][] A) {

        int[][] reverseA = new int[A[0].length][A.length];

        for (int i = 0;i < A.length;i++) {

            for (int j =0;j < A[i].length;j++) {

                reverseA[j][i] = A[i][j];
            }
        }

        return reverseA;
    }

    public static void main(String[] args) {

        int[][] A = new int[][]{{1,2,3},{4,5,6}};
        int[][] B = reverseArray(A);

        for (int i = 0; i < B.length; i++) {

            for (int j = 0; j < B[i].length; j++) {

                System.out.println(B[i][j]);
            }
        }
    }

}
