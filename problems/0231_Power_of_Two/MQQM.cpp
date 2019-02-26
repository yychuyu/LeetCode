/*
  题目：
  给定一个整数，编写一个函数来判断它是否是 2 的幂次方。
*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n < 0){//负数不会是2的幂
            return false;
        }
        
        int cnt = 0;
        for(int i=0; i<=30; i++){//在31位上，数一下1的个数
            int mask = 1 << i;
            if( (mask & n) == mask ){
                cnt++;
            }           
        }
        if(cnt == 1){
            return true;
        }
        
        return false;
    }
};
