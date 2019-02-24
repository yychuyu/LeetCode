/**
 * Author: Json Wan
 * Created at: 2018/12/21 23:09
 * Description:
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
 P   A   H   N
 A P L S I I G
 Y   I   R
 And then read line by line: "PAHNAPLSIIGYIR"
 Write the code that will take a string and make this conversion given a number of rows:
 string convert(string s, int numRows);
 Example 1:
 Input: s = "PAYPALISHIRING", numRows = 3
 Output: "PAHNAPLSIIGYIR"
 Example 2:
 Input: s = "PAYPALISHIRING", numRows = 4
 Output: "PINALSIGYAHRPI"
 Explanation:
 P     I    N
 A   L S  I G
 Y A   H R
 P     I
 思路：维护一个大小为numRows的数组分别记录对应行的字符，一共有两个变化方向，只要知道位置，就知道该往数组哪个元素加了，最后合并数组即可
 **/
public class wanxu_pursue_0006 {

    /**
     * 0.2722，时间复杂度应该是够的，空间复杂度应该可以继续优化
     * @param s
     * @param numRows
     * @return
     */
    public String convert(String s, int numRows) {
        //注意边界条件
        if(numRows==1){
            return s;
        }
        int posI=-1,posJ=0;
        boolean dir=true;
        String[] results=new String[numRows];
        for(int i=0;i<numRows;i++){
            results[i]="";
        }
        for(int i=0;i<s.length();i++){
            char ch=s.charAt(i);
            if(dir){
                posI+=1;
            }else{
                posI-=1;
                posJ+=1;
            }
            if(posI==numRows-1){
                dir=false;
            }else if(posI==0){
                dir=true;
            }
            results[posI]+=ch;
        }
        return String.join("",results);
    }

    /**
     *
     * @param s
     * @param numRows
     * @return
     */
    public String bestConvert(String s, int numRows) {
        int length = s.length();
        if (length <= numRows || numRows == 1) return s;
        char[] chars = new char[length];
        int step = 2 * (numRows - 1);
        int count = 0;
        for (int i = 0; i < numRows; i++){
            int interval = step - 2 * i;
            for (int j = i; j < length; j += step){
                chars[count] = s.charAt(j);
                count++;
                if (interval < step && interval > 0
                        && j + interval < length && count <  length){
                    chars[count] = s.charAt(j + interval);
                    count++;
                }
            }
        }
        return new String(chars);
    }

    public static void main(String[] args) {
        //PAHNAPLSIIGYIR
        System.out.println(new wanxu_pursue_0006().convert("PAYPALISHIRING",3));
        //PINALSIGYAHRPI
        System.out.println(new wanxu_pursue_0006().convert("PAYPALISHIRING",4));
        System.out.println(new wanxu_pursue_0006().convert("AB",1));
    }
}
