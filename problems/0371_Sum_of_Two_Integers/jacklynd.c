int getSum(int a, int b) {
                                    //代码思想为用位异或和位与得到加法效果
    if((a==1&&b==-1)||(a==-1&&b==1))    //特殊溢出待解决
        return 0;
    int sum, carry;
    
    sum = a ^ b;                    //位异或   处理0+1         
    
    carry = (a & b) << 1;         //位与后左移一位 处理1+1产生的进位

    if(carry != 0)                  //有进位情况时 执行
    {
        return getSum(sum, carry);  //将新值和进位传进新函处理
    }
    
    return sum;                     //无进位情况则顺序执行返回上层函数，返回值为sum
}                                   //这个地方的sum应该直接取出，再一层层出栈不必要的返回时间开销过大
