package LeetCodePart2;

import java.util.ArrayList;
import java.util.List;

/**
 * @Author: liuyunsheng
 * @Date: 2019/3/11 22:56
 * @Version 1.0
 * @Description:
 * 用户输入一个数字，然后用罗马数字表示
 */
public class RomaNumber {
    public String intToRoman(int num) {
        StringBuilder s=new StringBuilder();
        if (num<=0||num>9999){
            System.out.println("罗马数字不能表示这些数字");
        }else {
            List<Integer>list=new ArrayList<>();
            while (num>=0){
                list.add(num%10);
                num=num/10;
            }
            for (int i = list.size()-1; i >=0 ; i--) {

            }
        }


        return null;
    }
}
