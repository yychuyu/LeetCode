package test;

import org.junit.Test;

import java.util.ArrayList;
import java.util.List;

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
     * 在MATLAB中，有一个非常有用的函数 reshape，它可以将一个矩阵重塑为另一个大小不同的新矩阵，但保留其原始数据。

     给出一个由二维数组表示的矩阵，以及两个正整数r和c，分别表示想要的重构的矩阵的行数和列数。

     重构后的矩阵需要将原始矩阵的所有元素以相同的行遍历顺序填充。

     如果具有给定参数的reshape操作是可行且合理的，则输出新的重塑矩阵；否则，输出原始矩阵。
     * */
    public static int[][] matrixReshape(int[][] A, int r, int c) {

        int[][] B = new int[r][c];

        //先判断给定的参数所需要的元素数量是否与原数组所有的元素是否相同，如果不同则返回原矩阵
        int lineLen,columnLen,m=0,n=0;
        lineLen = A.length;
        columnLen = A[0].length;

        if(lineLen * columnLen != r * c) {
            return A;
        }

        //转换矩阵
        for (int i = 0; i < lineLen; i++) {

            for (int j = 0; j < columnLen; j++) {

                if(m >= c) {

                    m = 0;
                    n++;
                }
                B[n][m] = A[i][j];
                m++;
            }
        }

        return B;
    }

    public static void main(String[] args) {

        int[][] nums = {{1,2},{3,4}};
        matrixReshape(nums,3,4);
    }

}
