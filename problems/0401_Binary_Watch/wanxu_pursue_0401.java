import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * Created by Json Wan on 2018/11/5.
 * ��Ŀ������
 * A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).
 * <p>
 * Each LED represents a zero or one, with the least significant bit on the right.
 * <p>
 * <p>
 * For example, the above binary watch reads "3:25".
 * <p>
 * Given a non-negative integer n which represents the number of LEDs that are currently on, return all possible times the watch could represent.
 * <p>
 * Example:
 * <p>
 * Input: n = 1
 * Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
 * Note:
 * The order of output does not matter.
 * The hour must not contain a leading zero, for example "01:00" is not valid, it should be "1:00".
 * The minute must be consist of two digits and may contain a leading zero, for example "10:2" is not valid, it should be "10:02".
 * ����˼·��������ȫ���е��㷨�����Եݹ����ɣ��������п��ܵ������һһ�ж�ת������
 */


public class wanxu_pursue_0401 {

    private int[] getHoursAndMinutes(int[] digits) {
        int[] result = new int[2];
        int hours = 0;
        for (int i = 0; i < 4; ++i) {
            hours = hours * 2 + digits[i];
        }
        int minutes = 0;
        for (int i = 4; i < 10; ++i) {
            minutes = minutes * 2 + digits[i];
        }
        result[0] = hours;
        result[1] = minutes;
        return result;
    }

    private boolean isValidTime(int[] time) {
        if (time[0] > 11 || time[1] > 59) {
            return false;
        }
        return true;
    }

    private String convertTimeToString(int[] time){
        StringBuilder sb=new StringBuilder();
        sb.append(time[0]);
        sb.append(":");
        if(time[1]<10) {
            sb.append("0");
        }
        sb.append(time[1]);
        return sb.toString();
    }

    private List<List<Integer>> choose(int start,int end,int num){
        List<List<Integer>> result=new ArrayList<List<Integer>>();
        if(end-start+1==num){
            List<Integer> element = new ArrayList<Integer>();
            for(int i=start;i<=end;++i) {
                element.add(i);
            }
            result.add(element);
            return result;
        }
        if(num==0){
            return result;
        }
        else if(num==1){
            for(int i=start;i<=end;++i) {
                List<Integer> element = new ArrayList<Integer>();
                element.add(i);
                result.add(element);
            }
            return result;
        }else{
            //ѡ���һλ
            List<List<Integer>> subResult=choose(start+1,end,num-1);
            for(List<Integer> element:subResult){
                List<Integer> newElement = new ArrayList<Integer>();
                newElement.add(start);
                newElement.addAll(element);
                result.add(newElement);
            }
            //��ѡ��һλ
            List<List<Integer>> subResult2=choose(start+1,end,num);
            result.addAll(subResult2);
            return result;
        }
    }

    /**
     * ͨ��,5ms,46%
     * @param num
     * @return
     */
    public List<String> readBinaryWatch(int num) {
        List<String> result=new ArrayList<String>();
        //�߽��������
        if(num==0){
            result.add("0:00");
            return result;
        }
        //����C10(num)�����
        //�ⷨ1�������ڰ˻ʺ����⣬10��ѭ�����ɣ�ʱ�临�Ӷȸ�
        //�ⷨ2��ѡλ˼�룬ѡnum�μ��ɣ�����ѭ���������ǲ����ģ��޷�ʵʩ
        //�ⷨ3���ݹ�����
        List<List<Integer>> choices=choose(0,9,num);
        for(List<Integer> choice:choices){
            int[] digits=new int[10];
            for(Integer i:choice){
                digits[i]=1;
            }
            int[] hoursAndMinutes=getHoursAndMinutes(digits);
            if(isValidTime(hoursAndMinutes)){
                result.add(convertTimeToString(hoursAndMinutes));
            }
        }
        return result;
    }

    private int helper(int num) {
        int result = 0;
        while (num != 0) {
            if ((num & 1) == 1) {
                result++;
            }
            num >>= 1;
        }
        return result;
    }

    public List<String> bestReadBinaryWatch(int num) {
        List<String> result = new ArrayList<>();
        //�������е�Сʱ������������������п��ܵ����
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 60; j++) {
                int total = helper(i) + helper(j);
                if (total == num) {
                    String str = "";
                    str += i + ":";
                    if (j < 10) {
                        str += "0" + j;
                    } else {
                        str += j;
                    }
                    result.add(str);
                }
            }
        }
        return result;
    }

    public static void main(String[] args) {
        Scanner scanner=new Scanner(System.in);
        while(true){
            int n=scanner.nextInt();
            for(String x:new wanxu_pursue_0401().readBinaryWatch(n)){
                System.out.print(x+",");
            }
            System.out.println();
        }
    }
}
