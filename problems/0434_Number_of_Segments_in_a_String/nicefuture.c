int countSegments(char* s) {
    char *p = s;
    int cnt = 0;
    
    if (*p != '\0' && *p == 0) return 0;
    while (*p != '\0') {
        if (*p != ' ' && (*(p+1) == ' ' || *(p+1) == '\0')) {
            cnt++;
        }
        p++;
    }
    return cnt;
}
