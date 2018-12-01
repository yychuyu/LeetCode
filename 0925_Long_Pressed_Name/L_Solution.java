import java.util.Arrays;

/**
 *  created by LeiHauping on 2018/11/21
 */

public class Solution {
    public static void main(String[] args){
        String name="pyplrz";
        String typed="ppyypllr";
        System.out.println(new Solution().isLongPressedName(name,typed));

    }

    public boolean isLongPressedName(String name, String typed) {
        int i=0;
        int j=0;
        while (true){
            if(j==typed.length()&&i!=name.length()) return false;
            if(i==name.length()){//name遍历完。typed要么遍历完，要么最后一个字母长按
                if(j==typed.length()){
                    return true;
                }
                else {
                    while (j<typed.length()){
                        if(typed.charAt(j)!=typed.charAt(j-1)){
                            return false;
                        }
                        j++;
                    }
                    return true;
                }
            }
            if(name.charAt(i)!=typed.charAt(j)){
                if(j>=1&&typed.charAt(j)==typed.charAt(j-1)){
                    j++;
                    continue;
                }else{
                    return false;
                }
            }
            i++;j++;
        }
    }
}
