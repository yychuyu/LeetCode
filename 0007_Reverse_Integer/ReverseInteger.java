/**
 * Created by zhoudl on 2018/10/2.
 */
public class ReverseInteger {

    /*Given a 32-bit signed integer, reverse digits of an integer.

    Example 1:

    Input: 123
    Output: 321
    Example 2:

    Input: -123
    Output: -321
    Example 3:

    Input: 120
    Output: 21
    Note:
    Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range:
     [−231,  231 − 1].
     For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
    */

    public static int reverse(int x) {
        String temp;
        // 是否负数
        boolean isNegativeNumber = false;
        if (x == 0) {
            return x;
        }
        // 数置越界
        if (x == Integer.MIN_VALUE || x == Integer.MAX_VALUE) {
            return 0;
        }
        if (x < 0) {
            // 负数
            isNegativeNumber = true;
            x = -x;
        }
        // 正数
        temp = String.valueOf(x);
        StringBuilder resultStr = new StringBuilder(temp).reverse();
        if (isNegativeNumber) {
            temp = "-" + resultStr.toString();
        } else {
            temp = resultStr.toString();
        }
        Long res = Long.parseLong(temp);
        return (res > Integer.MAX_VALUE || res < Integer.MIN_VALUE) ? 0 : Integer.parseInt(res.toString());
    }

    public static int reverse_2(int x) {
        Long result = 0L;
        while (x != 0) {
            // 通过不断取余数的方式得到该值得最后一位数字
            result = result * 10 + x % 10;
            // 不断取整的方式缩小这个目标数字
            x /= 10;
        }
        return (result > Integer.MAX_VALUE || result < Integer.MIN_VALUE) ? 0 : Integer.parseInt(result.toString());
    }


    public static void main(String[] args) {
        Integer x = -2147483648;
        System.out.println(reverse(x));
    }

}
