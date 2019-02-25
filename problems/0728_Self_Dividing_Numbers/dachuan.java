class Solution {
    public List<Integer> selfDividingNumbers(int left, int right) {
        List<Integer> list = new ArrayList<>();
        //从left循环到right
        for (int i = left; i <= right; i++) {
            if (isSelfDivideNum(i)) {
                list.add(i);
            }
        }
        return list;
    }

    /*
    判断这个数是否是自除数
     */
    public boolean isSelfDivideNum(int num){
        //每个数循环（对10取余并测试是否可以整除、除以10并进入下一轮循环）
        int tmp = num;
        while (true) {
            //拿到余数
            int remainder = tmp % 10;
            //余数不能包含0
            if (remainder == 0) {
                return false;
            } else {
                //原数字要整除每一位
                if (num % remainder != 0) {
                    return false;
                } else {
                    //拿到下一轮的数字
                    tmp = tmp / 10;
                    if (tmp == 0) {
                        //运算结束
                        return true;
                    } else {
                        //进入下一轮
                    }
                }
            }
        }
    }
}