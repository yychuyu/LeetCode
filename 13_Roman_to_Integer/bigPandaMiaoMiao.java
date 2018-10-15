/*
罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。
字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。
通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：
I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。
示例 1:
输入: "III"
输出: 3

示例 2:
输入: "IV"
输出: 4

示例 3:
输入: "IX"
输出: 9

示例 4:
输入: "LVIII"
输出: 58
解释: L = 50, V= 5, III = 3.

示例 5:
输入: "MCMXCIV"
输出: 1994
解释: M = 1000, CM = 900, XC = 90, IV = 4.
*/

import java.util.Collections;
import java.util.HashMap;
import java.util.Map;

/**
 * @author : bigPandaMiaoMiao
 * @date：2018-10-15
 * @jdk:1.8.0_151
 */
public class Roman2Int {
    /**
     * 定义一个Map常量ROMAN_MAP用来存放罗马数字
     */
    private static final Map<String, String> ROMAN_MAP;

    //为ROMAN_MAP赋值
    static {
        Map<String, String> romanMap = new HashMap<>();
        romanMap.put("I", "1");
        romanMap.put("V", "5");
        romanMap.put("X", "10");
        romanMap.put("L", "50");
        romanMap.put("C", "100");
        romanMap.put("D", "500");
        romanMap.put("M", "1000");
        //自定义一个字母“E”作为结束符号使用
        romanMap.put("E", "0");
        ROMAN_MAP = Collections.unmodifiableMap(romanMap);
    }

    private int roman2Int(String romanString) {
        int result = 0;
        //将传入的罗马字母字符串末尾+“E”后，转换成字符数组romanChars备用
        char[] romanChars = (romanString + "E").toCharArray();
        int length = romanChars.length;
        //定义三个bool变量，用于存放六种特殊情况
        boolean condI, condX, condC;
        //循环，注意结束条件是length-1，此时就用到了之前自定义的结尾符号“E”，否则字符数组就越界了~~
        for (int i = 0; i < length - 1; i++) {
            //判断是否属于六种特殊情况
            condI = romanChars[i] == 'I' && (romanChars[i + 1] == 'V' || romanChars[i + 1] == 'X');
            condX = romanChars[i] == 'X' && (romanChars[i + 1] == 'L' || romanChars[i + 1] == 'C');
            condC = romanChars[i] == 'C' && (romanChars[i + 1] == 'D' || romanChars[i + 1] == 'M');
            //如果属于六种特殊情况的一种，就变成减，否则累加
            if (condI || condX || condC) {
                result = result - Integer.parseInt(ROMAN_MAP.get(String.valueOf(romanChars[i])));
            } else {
                result = result + Integer.parseInt(ROMAN_MAP.get(String.valueOf(romanChars[i])));
            }

        }
        return result;
    }

    public static void main(String[] args) {
        String input = "MCMXCIV";
        Roman2Int roman2Int = new Roman2Int();
        System.out.println("输入的罗马数字为：" + input);
        System.out.println("输出的整数为：" + roman2Int.roman2Int(input));
    }

}
