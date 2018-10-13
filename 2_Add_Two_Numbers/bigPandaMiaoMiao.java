/**************************************************************
 题目：
 The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

 Given two integers x and y, calculate the Hamming distance.

 Note:
 0 ≤ x, y < 231.

 Example:

 Input: x = 1, y = 4

 Output: 2

 Explanation:
 1   (0 0 0 1)
 4   (0 1 0 0)
 ?   ?

 The above arrows point to positions where the corresponding bits are different.

 释义：

 分析：
 两个数的汉明距离，可以理解为，二进制的情况下，两个数异或之后的数的1的个数。
 比如例子中，1和4,0001与0100异或得：0101，而0101中1的个数，即为汉明距离，可以理解位，从0001，变成0100，需要改变的位数。
 ***************************************************************/

/**
 * @author : bigPandaMiaoMiao
 * @date：2018-10-13
 * @jdk:1.8.0_151
 */

public class AddTwoNumbers {

    public int addTwoNumber(int x, int y) {
        int result = 0;
        int temp = x ^ y;
        //将x与y的异或值转换为二进制形式的String放到xor中
        String xor = Integer.toBinaryString(temp);
        System.out.println("x异或y的二进制为" + xor);
        //再将xor转换为char数组binChar
        char[] binChar = xor.toCharArray();
        //通过循环计算里面'1'的个数
        for (char c : binChar) {
            if (c == '1') {
                result++;
            }
        }
        return result;
    }

    public static void main(String[] args) {
        int x = 1, y = 4;
        int result;
        AddTwoNumbers addTwoNumbers = new AddTwoNumbers();
        System.out.println("x=" + x + "; y=" + y);
        result = addTwoNumbers.addTwoNumber(x, y);
        System.out.println("x与y的汉明距离为：" + result);


    }

}
