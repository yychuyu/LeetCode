import java.util.HashMap;
import java.util.Map;

/**
 * @Author: Json Wan
 * Created at: 2019/2/22.
 * Description:
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
 * <p>
 * Symbol       Value
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 * For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.
 * <p>
 * Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:
 * <p>
 * I can be placed before V (5) and X (10) to make 4 and 9.
 * X can be placed before L (50) and C (100) to make 40 and 90.
 * C can be placed before D (500) and M (1000) to make 400 and 900.
 * Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.
 * <p>
 * Example 1:
 * <p>
 * Input: "III"
 * Output: 3
 * Example 2:
 * <p>
 * Input: "IV"
 * Output: 4
 * Example 3:
 * <p>
 * Input: "IX"
 * Output: 9
 * Example 4:
 * <p>
 * Input: "LVIII"
 * Output: 58
 * Explanation: L = 50, V= 5, III = 3.
 * Example 5:
 * <p>
 * Input: "MCMXCIV"
 * Output: 1994
 * Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 * 思路：构建字典，转换即可，需要注意多字符的整体转换；
 */
public class wanxu_pursue_0013 {

    //灵活运用了特殊数字IV,IX等4和9的前一个字符比后一个字符小的特点，避免了提前构造出所有的key，使用switch语句也比HashMap要快，对最后一个特殊字符单独处理，避免了在程序中考虑边界问题，代码可谓优美。
    public static int bestRomanToInt(String s) {
        int num = 0;
        int n = s.length();
        for (int i = 0; i < n - 1; i++) {
            int curr = map(s.charAt(i));
            int next = map(s.charAt(i + 1));
            num = curr < next ? num - curr : num + curr;
        }
        num += map(s.charAt(n - 1));
        return num;
    }

    private static int map(char c) {
        switch (c) {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default:
                return 0;
        }
    }

    //AC,0.5318
    public int romanToInt(String s) {
        Map<String, Integer> map = new HashMap<>();
        map.put("I", 1);
        map.put("IV", 4);
        map.put("V", 5);
        map.put("IX", 9);
        map.put("X", 10);
        map.put("XL", 40);
        map.put("L", 50);
        map.put("XC", 90);
        map.put("C", 100);
        map.put("CD", 400);
        map.put("D", 500);
        map.put("CM", 900);
        map.put("M", 1000);
        int i = 0, j = 0;
        int l = s.length();
        int result = 0;
        while (i < l) {
            StringBuilder ch = new StringBuilder();
            ch.append(s.charAt(i));
            j = i + 1;
            if (j < l) {
                ch.append(s.charAt(j));
                while (map.keySet().contains(ch.toString())) {
                    j++;
                    if (j >= l) {
                        break;
                    } else {
                        ch.append(s.charAt(j));
                    }
                }
            }
            if (j < l) {
                result += map.get(ch.toString().substring(0, ch.length() - 1));
            } else {
                result += map.get(ch.toString());
            }
            i = j;
        }
        return result;
    }

    public static void main(String[] args) {
        wanxu_pursue_0013 instance = new wanxu_pursue_0013();
        System.out.println(instance.romanToInt("I") == 1);
        System.out.println(instance.romanToInt("III") == 3);
        System.out.println(instance.romanToInt("IV") == 4);
        System.out.println(instance.romanToInt("IX") == 9);
        System.out.println(instance.romanToInt("LVIII") == 58);
        System.out.println(instance.romanToInt("MCMXCIV") == 1994);
        System.out.println(instance.romanToInt("MMM") == 3000);
    }
}
