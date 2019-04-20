bool judgeCircle(char* moves) {
    int cnt[255] = {};
    char *p = moves;
    while (*p != '\0') {
        cnt[*p]++;
        p++;
    }
    if (cnt['U'] == cnt['D'] && cnt['L'] == cnt['R']) return true;
    else return false;
}
