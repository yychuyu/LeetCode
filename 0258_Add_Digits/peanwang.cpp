/*
using recursion
*/
class Solution {
public:
    int addDigits(int num) {
        if(num<10)
            return num;
        else{
            int result = 0;
            while(num!=0){
                result +=num%10;
                num/=10;
            }
            return addDigits(result);
        }
    }
};
/*
 a trick way:
	Ak*10k + A(k-1)*10(k-1)+ ....... A0
	=Ak*(9+1)k + A(k-1)*(9+1)(k-1)+ ....... A0
*/
class Solution {
public:
    int addDigits(int num) {
        return (num-1)%9+1;
    }
};