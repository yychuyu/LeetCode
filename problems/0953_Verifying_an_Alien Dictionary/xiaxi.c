bool isAlienSorted(char** words, int wordsSize, char* order) {
    int map[26];
    for(int i = 0;i < strlen(order);i++)
        map[order[i] - 'a'] = i;
    for(int i = 1;i < wordsSize;i++){
        int cmp = 0;
        for(int j = 0,k = 0;j < strlen(words[i-1]) && k < strlen(words[i]) && cmp == 0;j++,k++)
            cmp = map[words[i-1][j] - 'a'] - map[words[i][k] - 'a'];
        if(cmp == 0)
            cmp = strlen(words[i-1]) - strlen(words[i]);
        if(cmp > 0)
            return false;
    }
    return true;
}
