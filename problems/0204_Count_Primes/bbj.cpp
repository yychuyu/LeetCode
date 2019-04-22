// 有点问题，跑的太慢了
class Solution {
public:
    int isprime(int n){
        for (int i = 2; i <= sqrt(n); i++){
            if (n % i == 0){
                return 0;
            }
        }
        return 1;
    }
    int countPrimes(int n) {
        int cnt = 0;
        for (int i = 2; i < n; i++){
            if (isprime(i)){
                ++cnt;
            }
        }
        return cnt;
    }
};
