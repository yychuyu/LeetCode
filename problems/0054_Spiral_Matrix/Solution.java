import java.util.ArrayList;
import java.util.List;

/**
 * * @ClassName Solution
 * * @Description 螺旋矩阵
 * * @Author luoquan
 * * @Email luo.quan@aliyun.com
 * * WeChat luo_quan1982
 * * @Date 2018/11/16 9:47
 * * 解题思路
 * * 使用了三角函数
 * * 初始的是后沿着x轴(towards为0，将column看作x轴，row看作y轴)角度为0一次取出数组中元素
 * * 遇到以下情况towards旋转顺时针旋转90度，因为我们的坐标是y轴朝下的，所以相当于标准二维坐标逆时针旋转90度，也就是π/2.
 * * 1、碰到数组边缘，也就是x<0 或x>column,或y<0 或y>row
 * * 2、遇到我们已经读取的元素时(取出元素，即将数组中的元素放到list中后我们会通过和matrix数组同样大小的布尔数组来标记此位置的元素已经读取)
 **/

class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> list = new ArrayList<>();
        if ((matrix == null || matrix.length == 0) || (matrix.length == 1 && matrix[0].length == 0))
            return list;

        int row = matrix.length;
        int column = matrix[0].length;

        int size = row * column;
        boolean[][] filled = new boolean[row][column];

        int x = 0, y = 0, k = 0;
        int testX = 0, testY = 0;
        double towards = 0;


        for (int i = 0; i < size; i++) {
            testX = x + (int) Math.cos(towards);
            testY = y + (int) Math.sin(towards);

            if (testX < 0 || testX > column - 1
                    || testY < 0 || testY > row - 1
                    || filled[testY][testX]) {
                k = ++k % 4;//其实可以和下面的合并写成towards=++k%4*Math.PI/2,但这样可以防止k过大(不过好像也没关系^__^)
                towards = k * Math.PI / 2;
            }
            list.add(matrix[y][x]);
            filled[y][x] = true;
            x += (int) Math.cos(towards);
            y += (int) Math.sin(towards);
        }
        return list;
    }
}