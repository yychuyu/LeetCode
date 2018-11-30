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
     * 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
     * 在杨辉三角中，每个数是它左上方和右上方的数的和。

     示例:

     输入: 5
     输出:
     [
     [1],
     [1,1],
     [1,2,1],
     [1,3,3,1],
     [1,4,6,4,1]
     ]
     * */
    private static List<List<Integer>> generate(int numRows) {
        List<List<Integer>> triangle = new ArrayList<List<Integer>>();

        //第一种情况，如果用户请求0行，就返回0行
        if (numRows == 0) {
            return triangle;
        }

        //第二种情况，第一行总是1
        triangle.add(new ArrayList<Integer>());
        triangle.get(0).add(1);

        for (int rowNum = 1; rowNum < numRows; rowNum++) {
            List<Integer> row = new ArrayList<>();
            List<Integer> prevRow = triangle.get(rowNum-1);

            //第一列始终为1
            row.add(1);

            //除了第一列和最后一列，三角形的其他元素等于左上方和右上方的和
            for (int j = 1; j < rowNum; j++) {
                row.add(prevRow.get(j-1) + prevRow.get(j));
            }

            //最后一列始终为1
            row.add(1);

            triangle.add(row);
        }

        return triangle;
    }

    public static void main(String[] args) {

        generate(5);
    }

}
