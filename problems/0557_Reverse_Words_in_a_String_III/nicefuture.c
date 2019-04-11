void reverse(char *low, char *ceiling) {
    int len = ceiling-low+1;
    for (int i=0; i<len/2; i++) {
        char t = low[i];
        low[i] = low[len-i-1];
        low[len-i-1] = t;
    }
}

char* reverseWords(char* s) {
    char *p = s, *low = s;
    while (*p != '\0') {
        if (*p != ' ' && (*(p+1) == ' ' || *(p+1) == '\0')) {
            reverse(low, p);
            low = p+2;
        }
        p++;
    }
    return s;
}
