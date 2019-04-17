class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    int max = 0;
    int tmp = 0;
    int l, r, i;
    int N = s.size();
    for (l = 0, r = 0; r <= N; r++) {
        for (i = l; i <= r; i++) {
            if (s[i] == s[r]) {
                if (tmp > max)   max = tmp;
                break;
            }
        }
        if (i == r)    tmp++;
	else {
            l = i + 1;tmp = r - i;
            }
    }
    return max;
    }
};
this file is added by shyshy
