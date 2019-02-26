/**
 * @Author 宋宗垚
 * @Date 2018/11/30 20:57
 * @Description TODO
 */
/*
我们称一个数 X 为好数, 如果它的每位数字逐个地被旋转 180 度后，我们仍可以得到一个有效的，且和 X 不同的数。要求每位数字都要被旋转。

如果一个数的每位数字被旋转以后仍然还是一个数字， 则这个数是有效的。0, 1, 和 8 被旋转后仍然是它们自己；2 和 5 可以互相旋转成对方；6 和 9 同理，除了这些以外其他的数字旋转以后都不再是有效的数字。

现在我们有一个正整数 N, 计算从 1 到 N 中有多少个数 X 是好数？

示例:
输入: 10
输出: 4
解释:
在[1, 10]中有四个好数： 2, 5, 6, 9。
注意 1 和 10 不是好数, 因为他们在旋转之后不变。
 */
public class RotatedDigits_788 {
    public boolean isGood(String str){
        boolean flag1 = false;
        boolean flag2 = false;
        if(str.contains("3") ||str.contains("4") ||str.contains("7")){
            flag1 = false;
        }else {
            flag1 = true;
        }
        if(str.contains("2")||str.contains("5")||str.contains("6")||str.contains("9")){
            flag2 = true;
        }
        return flag1 && flag2;
    }

    public int rotatedDigits(int N) {
        int count = 0;
        for(int i=1;i<=N;i++){
            if(isGood(String.valueOf(i))){
                count++;
            }
        }

        return count;
    }
}
