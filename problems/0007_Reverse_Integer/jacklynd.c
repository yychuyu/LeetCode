class Solution {
public:
    int reverse(int x) {   
    int flog1 = 0x7fffffff;         
    int flog2 = (int)0x80000000;
    int rev=0;
    int temp;
    while(x!=0){
        temp=x%10;
        x=x/10;
        if(rev>flog1/10||(rev==flog1/10)&& temp>7) return 0;     
        //本题以数学方法进行屏蔽溢出情况，常见堆栈处理对于这种简单问题的适用可能耗时更长，资源耗用更多。
        if(rev<flog2/10||(rev==flog2/10 && temp<-8)) return 0;
        rev=rev*10+temp;
    }
    return rev;
    }
};