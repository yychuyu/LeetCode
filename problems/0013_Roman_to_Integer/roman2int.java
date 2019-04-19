package LeetCodePart2;

import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * @Author: liuyunsheng
 * @Date: 2019/3/12 22:22
 * @Version 1.0
 * @Description:罗马数字转整数
 */
public class roman2int {
    public int romanToInt(String s) {
        int result=0;
        Map<String,Integer> map=new HashMap<>();
        List<Integer> list= Arrays.asList(1000,900,500,400,100,90,50,40,10,9,5,4,1);
        List<String> list1=Arrays.asList("M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I");
        for (int i = 0; i <13 ; i++) {
            map.put(list1.get(i),list.get(i));
        }
        while (s.length()>0){
            if (s.length()>1){
                String s1=s.substring(0,2);
                if (list1.contains(s1)){
                    result+=map.get(s1);
                    s=s.substring(2,s.length());
                }else {
                    result+=map.get(s.substring(0,1));
                    s=s.substring(1,s.length());
                }
            }else {
                result+=map.get(s);
                break;
            }
        }
        return result;
    }

    public static void main(String[] args) {
        roman2int roman2int=new roman2int();
        System.out.println(roman2int.romanToInt("IV"));
    }
}
