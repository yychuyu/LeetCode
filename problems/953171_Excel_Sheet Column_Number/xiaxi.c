int titleToNumber(char* s) {
    int i =0,sum = 0;
    while(s[i]!='\0')
        sum = sum * 26 + (s[i++]-64);
    return sum;
}
