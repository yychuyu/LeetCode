int findLUSlength(char* a, char* b) {
    if (strcmp(a, b) == 0) {
        return -1;
    } else {
        int len_a = strlen(a), len_b = strlen(b);
        return len_a > len_b ? len_a : len_b;
    }
}
