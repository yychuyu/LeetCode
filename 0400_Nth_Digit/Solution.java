class Solution {
    public int findNthDigit(int n) {
        // 定义计算的区域
        int arrayType = 1;
        long digitNum = 9;

        // 从第一个0到9的区域减起,找到当前数对应的区域
        while(n > digitNum*arrayType){
            n -= (int) digitNum*arrayType ;
            arrayType++;
            digitNum*=10;
        }

        int indexInSubRange = (n -1) / arrayType;
        int indexInNum = (n -1) % arrayType;

        int num = (int)Math.pow(10,arrayType - 1) + indexInSubRange ;
        int result = Integer.parseInt((""+num).charAt(indexInNum)+"");
        return result;
    }
}
