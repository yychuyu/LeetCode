class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        int MAX = 214748364;
        int MIN = -214748364;
        while (x != 0){
            int pop = x % 10;
            x = x / 10;
            // avoid overflow
            if (rev > MAX || rev == MAX && pop > 7)
                return 0;
            if (rev < MIN || rev == MIN && pop < -8)
                return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};
