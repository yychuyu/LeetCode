/*
  题目：
  从1...n选一个数字，然后猜选了什么数字
*/

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int s=1,e=n;
        while(s<=e){
            int m=(e-s)/2+s;  
            //int m=(e+s)/2; //这句不行，s+e的结果会超出int范围
            int ret=guess(m);
            if(ret==0)
                return m;
            else
                ret==1 ? s=m+1 : e=m-1;
        }
        return -1;
    }
};
