import java.util.HashSet;
import java.util.Set;

/**
 * @author: zhoudongliang
 * @date: 2018/9/21 17:24
 * @description:
 */
public class JewelsAndStones {

    /*
    題目：

    You're given strings J representing the types of stones that are jewels, and S representing the stones you have.
    Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

    The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive,
    so "a" is considered a different type of stone from "A".

    Example 1:
    Input: J = "aA", S = "aAAbbbb"
    Output: 3

    Example 2:
    Input: J = "z", S = "ZZ"
    Output: 0

    Note:
    S and J will consist of letters and have length at most 50.
    The characters in J are distinct.

    大概意思是：

    给定字符串J和S，求S中在J中出现的字符总数。
    注意，区分大小写即a和A不一样。

    词汇：
    representing 代表
    jewels 珠宝
    stones 石头
    guaranteed 保证
    */

    /**
     * 解法1
     * 使用Hash方法
     *
     * 通过遍历字符串S和J，两两进行比较，判断stone中有多少颗jewel。
     *
     * 时间复杂度为O(s * j)。(s为字符串S的长度，j为字符串J的长度)。
     * 空间复杂度为O(1)。
     *
     */
    public static int countsJewelsAndStones (String jewels,String stones){
        int count = 0;
        // 判断边界条件
        if (stones == null || jewels == null) {
            return 0;
        }
        Set set = new HashSet<>();
        // 字符串转数组 利用toCharArray方法转换
        char[] arrayJewels = jewels.toCharArray();
        char[] arrayStones = stones.toCharArray();
        // 把S字符串按字节放到set集合中
        for (char temp : arrayJewels) {
            set.add(temp);
        }
        // 判断具体出现次数
        for (char temp : arrayStones) {
            if (set.contains(temp)) {
                count ++;
            }
        }
        return count;
    }

    /**
     *  暴力解法
     *  时间复杂度：O（n^2）                            
     *  空间复杂度：O（1)
     */

    public static int countsJewelsInStones2(String Jewels, String stones) {
        int result = 0;
        char[] arrayJewels = Jewels.toCharArray();
        char[] arrayStones = stones.toCharArray();
        for(int i = 0 ; i < arrayJewels.length ; i++) {
            for(int j = 0 ; j < arrayStones.length ; j++) {
                if(arrayJewels[i] == arrayStones[j]) {
                    result++;
                }
            }
        }
        return result;
    }
    
    public static void main(String[] args) {
        String j = "z",s = "ZZ";
        int count = countsJewelsAndStones(j, s);
        System.out.println(count);
        System.out.println(countsJewelsInStones2(j,s));
    }

}
