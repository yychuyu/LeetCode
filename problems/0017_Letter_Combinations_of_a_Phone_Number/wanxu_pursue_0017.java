import java.util.ArrayList;
import java.util.List;

/**
 * Author: Json Wan
 * Created at: 2019/3/2 13:12
 * Description:
 *17. Letter Combinations of a Phone Number
 Medium
 Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

 A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
 Example:
 Input: "23"
 Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 思路：全排列，递归是最简单的解法，考虑循环解决
 **/
public class wanxu_pursue_0017 {

    //AC,1.00，开心！循环解法应该是最优的了，其他很多解法都是递归
    public List<String> letterCombinations(String digits) {
        String[] map=new String[]{"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        List<String> result=new ArrayList<>();
        List<String> lastResult;
        int l=digits.length();
        if(l==0){
            return result;
        }else{
            result.add("");
        }
        for(int i=0;i<l;i++){
            lastResult=result;
            result=new ArrayList<>();
            String str=map[(int)(digits.charAt(i))-50];
            int strLength=str.length();
            for(String s:lastResult){
                for(int j=0;j<strLength;j++){
                    result.add(s+str.charAt(j));
                }
            }
        }
        return result;
    }

    public static void main(String[] args) {
        wanxu_pursue_0017 instance=new wanxu_pursue_0017();
        System.out.println(instance.letterCombinations(""));
        System.out.println(instance.letterCombinations("23"));
        System.out.println(instance.letterCombinations("234"));
        System.out.println(instance.letterCombinations("23456789"));
    }
}
