
/**
 * Created by Json Wan on 2018/10/29.
 * Description��
 * Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...

 Note:
 n is positive and will fit within the range of a 32-bit signed integer (n < 231).

 Example 1:

 Input:
 3

 Output:
 3
 Example 2:

 Input:
 11

 Output:
 0

 Explanation:
 The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.
 ˼·���ҵ�nλ�����ڵ�����������ͨ�ʽ���ɣ�
 S=9*10^(1-1)*1+9*10^(2-1)*2+9*10^(3-1)*3+����+9*10^(n-1)*n
 */
public class wanxu_pursue {
    /*
    �ⷨͨ����3ms
     */
    public int findNthDigit(int n) {
        //����ע�������long���ͣ�int+int���ܻ����long�����뿼�����ͱ߽簲ȫ������
        long s=0;
        int num=0;
        while(s<n){
            num++;
            s+=9*Math.pow(10,num-1)*num;
        }
        s-=9*(long)(Math.pow(10,num-1))*num;
        //Ҫ�ҵ�����λ��ĳһ��numλ����
        //����num-1λ���󣬻������
        long res=n-s;
        int count=(int)(res/num);
        int lastRes=(int)(res%num);
        //Ҫ�������λ��number��
        int number=(int)(Math.pow(10,num-1))+count;
        if(lastRes==0){
            number=number-1;
            String numStr=""+number;
            return Integer.parseInt(numStr.charAt(numStr.length()-1)+"");
        }else{
            String numStr=""+number;
            return Integer.parseInt(numStr.charAt(lastRes-1)+"");
        }
    }
    public static void main(String[] args) {
        //System.out.println("hello");
        wanxu_pursue testInstance=new wanxu_pursue();
        System.out.println(testInstance.findNthDigit(1000000000));
        for (int i = 1; i < 100; i++) {
            System.out.println(testInstance.findNthDigit(i));
        }
    }
}
