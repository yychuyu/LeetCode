bool validPalindrome(char* s) {
    int deleted = 0, len = strlen(s);
    for (int i=0, j=len-1; i<=j; i++,j--) {
        // printf("%c", s[j]);
        if (s[i] != s[j]) {
            // printf("%c %c", s[i], s[j]);
            if (!deleted && s[i+1] == s[j] && (s[i+2] == s[j-1] || i+1 == j)) {
                deleted = 1;
                i++;
            } else if (!deleted && s[i] == s[j-1] && (s[i+1] == s[j-2] || j-1 == i)) {
                deleted = 1;
                j--;
            } else {
                return false;
            }
        }
    }
    return true;
}
