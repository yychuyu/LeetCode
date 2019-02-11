char* convertToTitle(int n) {
    int maxLen = 8;
    char *r = (char*) malloc (sizeof(char)*maxLen);
    char *p = r+maxLen-1;
    *p = '\0';
    p--;
    int reaLen = 1;  //include '\0'
    int remain = 0;
    while (n != 0) {
        remain = n % 26;
        *p = 'A'+(remain==0 ? 26 : remain) - 1;  //若为0，则对应26
        n /= 26;
        if (remain == 0) n--;  //消除进位的影响
        p--;
        reaLen++;
        // printf("%d %d\n", n, remain);
    }
    return r+(maxLen-reaLen);
}
