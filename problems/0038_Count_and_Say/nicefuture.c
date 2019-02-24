char* countAndSay(int n) {
    char* str = (char*) malloc(10000*sizeof(char));
    memset(str, 0, sizeof(str));
    str[0] = '1';
    while (n > 1) {
        char temp[10000];
        char *o = str, *t = temp;
        while (*o != '\0') {
            int cnt = 0;
            char c = *o;
            while (*o == c) {
                cnt++;
                o++;
            }
            *t = '0'+cnt;
            *(t+1) = c;
            t += 2;
        }
        *t = '\0';
        strcpy(str, temp);
        n--;
    }
    return str;
}
