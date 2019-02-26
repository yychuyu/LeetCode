int titleToNumber(char* s) {
    //　26进制
    int sum = 0;
    char *p = s;
    while (*p != '\0') {
        sum = sum*26 + (*p-'A'+ 1);
        p++;
    }
    // printf("%d\n", sum);
    return sum;
}
