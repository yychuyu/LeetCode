bool isCapital(char c) {
    return c >= 'A' && c <= 'Z';
}
bool allCapital(char *p) {
    while (*p != '\0') {
        if (!isCapital(*p)) return false;
        p++;
    }
    return true;
}
bool allLower(char *p) {
    while (*p != '\0') {
        // printf("%c is not capital.\n", *p);
        if (isCapital(*p)) return false;
        p++;
    }
    return true;
}

bool detectCapitalUse(char* word) {
    char *p = word;
    if (isCapital(*p)) {
        if (isCapital(*(++p))) {
            // printf("is capital");
            return allCapital(p);  //剩余全是大写
        } else {
            // printf("not capital.");
            return allLower(p);  //剩余全是小写
        }
    } else {
        return allLower(p);  //全是小写
    }
}
