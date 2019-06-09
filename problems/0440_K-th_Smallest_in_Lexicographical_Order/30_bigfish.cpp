class Solution {
public:
    typedef long long int lint;

    lint prefix(lint pre, lint n) {

        if(pre > n) return 0;
        lint s = 0, d = 1;
        while(pre * d + d - 1 <= n) {
            s += d;
            d *= 10;
        }
        if(pre * d > n) return s;
        else return s + (n - pre * d + 1);
    }

    lint solve(lint pre, lint n, lint k) {
        
        if(pre) if(k == 1) return pre; else k--;
        for(lint i = pre? 0: 1; i < 10; i++) {
            lint pn = prefix(pre * 10 + i, n);
            
            if(k > pn) {
                k -= pn;
            } else {
                return solve(pre * 10 + i, n, k);
            }
        }
        return 0;
    }

    int findKthNumber(int n, int k) 
    {
        return solve(0, n, k);
    }
};
