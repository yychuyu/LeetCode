char* toLowerCase(char* str) {
    char *p = str;
    while (*p != '\0') {
        if (*p >= 'A' && *p <= 'Z') *p = 'a' + (*p - 'A');
        p++;
    }
    return str;
}
