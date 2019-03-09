class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0;
        int max_len = 0;
        for(int i=0; i<s.length();) {
            int left = i;
            int right = i;
            while(right < s.length()-1 && s[right] == s[right+1]) {
                right++;
            }
            i = right + 1;
            while(left > 0 && right < s.length()-1 && s[left-1] == s[right+1]) {
                left--;
                right++;
            }
            if(max_len < (right - left + 1)) {
                start = left;
                max_len = right - left + 1;
            }
        }
        return s.substr(start, max_len);
    }
};
