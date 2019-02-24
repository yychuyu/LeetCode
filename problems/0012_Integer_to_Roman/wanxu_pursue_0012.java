import java.util.HashMap;
import java.util.Iterator;
import java.util.TreeSet;

/**
 * Author: Json Wan
 * Created at: 2019/1/28 15:13
 * Description:
 * 12. Integer to Roman
 * Medium
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
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
 * Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.
 * Example 1:
 * Input: 3
 * Output: "III"
 * Example 2:
 * Input: 4
 * Output: "IV"
 * Example 3:
 * Input: 9
 * Output: "IX"
 * Example 4:
 * Input: 58
 * Output: "LVIII"
 * Explanation: L = 50, V = 5, III = 3.
 * Example 5:
 * Input: 1994
 * Output: "MCMXCIV"
 * Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 * 思路：曾经遇到过的一道面试题，主要是要注意9,4等等这些数字；
 * 其实就是一个贪心算法而已。
 **/
public class wanxu_pursue_0012 {


    public String bestIntToRoman(int num) {
        int[] values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        String[] strs = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < values.length; i++){
            while(num >= values[i]){
                num -=values[i];
                sb.append(strs[i]);
            }
        }
        return sb.toString();
    }

    //AC,22.36%
    public String intToRoman(int num) {
        StringBuffer result = new StringBuffer();
        //建表存储对应关系
        HashMap<Integer, String> map = new HashMap<>();
        //基础关系
        map.put(1, "I");
        map.put(2, "II");
        map.put(3, "III");
        map.put(5, "V");
        map.put(10, "X");
        map.put(50, "L");
        map.put(100, "C");
        map.put(500, "D");
        map.put(1000, "M");
        //扩展关系
        map.put(4, "IV");
        map.put(9, "IX");
        map.put(40, "XL");
        map.put(90, "XC");
        map.put(400, "CD");
        map.put(900, "CM");
        //将keyset降序排列
        TreeSet<Integer> set = new TreeSet<>();
        set.addAll(map.keySet());
        Iterator<Integer> iter = set.descendingIterator();
        while (num > 0 && iter.hasNext()) {
            int t = iter.next();
            if (num >= t) {
                int s = num / t;
                num = num - t * s;
                while (s > 0) {
                    result.append(map.get(t));
                    s--;
                }
            }
        }
        return result.toString();
    }

    public static void main(String[] args) {
        wanxu_pursue_0012 instance = new wanxu_pursue_0012();
        System.out.println(instance.intToRoman(200).equals("CC"));
        System.out.println(instance.intToRoman(3).equals("III"));
        System.out.println(instance.intToRoman(4).equals("IV"));
        System.out.println(instance.intToRoman(9).equals("IX"));
        System.out.println(instance.intToRoman(58).equals("LVIII"));
        System.out.println(instance.intToRoman(1994).equals("MCMXCIV"));
    }
}
