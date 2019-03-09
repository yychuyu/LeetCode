int lengthOfLongestSubstring(char* s) {
    int exist[1000], len = 0;
    memset(exist, 0, sizeof(exist));
    char *p = s, *q = s;

    while (*q != '\0') {
        if (exist[*q]) {
            exist[*p] = 0;
            p++;
        } else {
            exist[*q] += 1;
            // putchar(*q);
            q++;
            len = len > (q - p) ? len : (q-p);
            // printf(" %d\n", len);
        }
    }
    return len;
}
