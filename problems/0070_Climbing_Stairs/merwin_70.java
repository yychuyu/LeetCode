/*递归消耗太大，这题只能用迭代*/
class Solution {
    public int climbStairs(int n) {
        if(n<=0){
            return 0;
        }
        if(n<3){
            return n;
        }
        int a = 1;
        int b = 2;
        for(int i=3; i<=n;i++){
            int tem = a;
            a = b;
            b= tem+b;
        }
        return b;
    }
}