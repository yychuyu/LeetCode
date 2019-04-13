bool checkRecord(char* s) {
    char *p = s;
    int absent = 0, late = 0;
    while (*p != '\0') {
        if (*p == 'A') {
            absent++;
            late = 0;
        }
        else if (*p =='L') late++;
        else late = 0;
        if (absent > 1 || late > 2) return false;
        p++;
    }
    return true;
}

/*
bool checkRecord(char* s) {
    char *p = s;
    int absent = 0, late = 0;
    while (*p != '\0') {
        if (*p == 'P') {
            p++;
        }
        if (*p != '\0' && *p == 'A') {
            absent++;
            p++;
        }
        if (*p != '\0' && *p == 'L') {
            int cnt = 0;
            for (int i=0; *p!='\0' && i<3; i++,p++) {
                // putchar(*p);
                if (*p == 'L') cnt++;
                else break;
            }
            if (cnt >= 3) late = 1;
        }
        if (absent > 1 || late == 1) return false;
    }
    return true;
}
*/
