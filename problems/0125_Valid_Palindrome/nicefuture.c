bool isPalindrome(char* s) {
    int len = 0;
    if (!(len=strlen(s))) return true;
    char *i = s, *j = s+(len-1);
    while (i < j) {
        while (i < j && !(*i >= 'a' && *i <= 'z') && !(*i >= 'A' && *i <= 'Z') &&
               !(*i >= '0' && *i <= '9')) i++;  //跳过非字母及数字的字符
        while (i < j && !(*j >= 'a' && *j <= 'z') && !(*j >= 'A' && *j <= 'Z') &&
               !(*j >= '0' && *j <= '9')) j--;
        if (*i >= 'A' && *i <= 'Z') *i = 'a'+(*i-'A');  //比较前确保为小写
        if (*j >= 'A' && *j <= 'Z') *j = 'a'+(*j-'A');
        if (*i != *j) return false;  //不同则非回文
        i++;
        j--;
    }
    return true;
}
