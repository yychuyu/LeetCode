int lengthOfLastWord(char* s) {
    int len = 0;
    char *c = s;
    
    while (*c != '\0') {
        if (*c != ' ') {
            len++;
        } else if (*c == ' ' && (*(c+1) != ' ' && *(c+1) != '\0')){
            len = 0;
        }
        c++;
    }
    
    return len;
}
