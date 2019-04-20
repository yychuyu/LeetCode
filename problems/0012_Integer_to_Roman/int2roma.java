package LeetCodePart2;


import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * @author 刘云生
 * @date 2019/3/1221:01
 * 整数转罗马数字
 */
public class int2roma {
    public String int2roma(int num){
        List<Integer> list= Arrays.asList(1000,900,500,400,100,90,50,40,10,9,5,4,1);
        List<String> list1=Arrays.asList("M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I");
        StringBuilder stringBuilder=new StringBuilder();
        for (int i = 0; i <13 ; i++) {
            while (num>=list.get(i)){
                stringBuilder.append(list1.get(i));
                num=num-list.get(i);
            }
        }
        return stringBuilder.toString();
    }

    public static void main(String[] args) {
        int2roma int2roma=new int2roma();
        System.out.println(int2roma.int2roma(1994));
    }
}
