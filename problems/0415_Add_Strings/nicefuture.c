char* addStrings(char* num1, char* num2) {
    int len1 = strlen(num1), len2 = strlen(num2);
    char *p = num1+len1-1, *q = num2+len2-1;
    
    int cnt = 0; 
    char *result = (char*) malloc(sizeof(char)*5100);
    char *r = result + 5099;
    *r = '\0';
    r--;
    
    // 求和，注意进位
    int add = 0;
    while (p >= num1 && q >= num2) {
        *r = (*p+*q+add) % '0' % 10 + '0';
        if ((*p+*q+add) % '0'> 9) add = 1;
        else add = 0;
        p--;
        q--;
        r--;
        cnt++;
    }
    
    while (p >= num1) {
        *r = (*p+add) % '0' % 10 + '0';
        if ((*p+add) % '0'> 9) add = 1;
        else add = 0;
        p--;
        r--;
        cnt++;
    }
    while (q >= num2) {
        *r = (*q+add) % '0' % 10 + '0';
        if ((*q+add) % '0'> 9) add = 1;
        else add = 0;
        q--;
        r--;
        cnt++;
    }
    
    // 如果最后还有进位
    if (add > 0) {
        *r = add+'0';
        cnt++;
    }
    
    return result+(5099-cnt);
}
