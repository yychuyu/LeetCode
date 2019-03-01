class Solution {
public:
    int rotatedDigits(int N) {
        int res = 0;
        for (int i = 1; i <= N; ++i) {
            if (check(i)) ++res;
        }
        return res;
    }
    bool check(int k) {
        string str = to_string(k);
        bool flag = false;
        for (char c : str) {
            if (c == '3' || c == '4' || c == '7') return false;
            if (c == '2' || c == '5' || c == '6' || c == '9') flag = true;;
        }
        return flag;
    }
};
