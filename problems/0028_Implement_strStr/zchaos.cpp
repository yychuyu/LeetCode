class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size();
    int n = needle.size();
    if (!n) 
        return 0;
        //��ʼ���� 
    for (int i = 0; i < m - n + 1; i++) {
        int k = i, j = 0;
        while (j < n) {
            if (needle[j] == haystack[k]) {
                j++;
                k++;
            } else {
                break;
            }
        }
        if (j == n)
            return i;
    }
    return -1;
    }
};
