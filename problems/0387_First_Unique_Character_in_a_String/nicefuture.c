int firstUniqChar(char* s) {
    char *p = s;
    int cnt[300] = {};
    
    while (*p != '\0') {
        cnt[*p]++;
        p++;
    }
    
    int count = 0;
    p = s;
    while (*p != '\0') {
        if (cnt[*p] == 1) {
            return count;
        }
        count++;
        p++;
    }
    
    return -1;
}
