/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findAndReplacePattern(char** words, int wordsSize, char* pattern, int* returnSize) {
    struct map {
        char src[26] ;
        char dst[26];
        int top;
    } pattern_map;

    int len;
    int j, k;
    
    char **result = (char **) malloc(wordsSize * sizeof(char *));
    *returnSize = 0;
    
    for (int i = 0; i < wordsSize; i++) {
        len = strlen(words[i]);
        memset(&pattern_map, 0, 52);
        pattern_map.top = 0;
        for (j = 0; j < len; j++) {
            for (k = 0; k < pattern_map.top; k++) {
                if (pattern_map.src[k] == words[i][j]) {
                    if (pattern_map.dst[k] != pattern[j]) {
                        j = len + 2;
                    }
                    break;
                }
                else if (pattern_map.dst[k] == pattern[j]) {
                    j = len + 2;
                    break;
                }
            }
            if (k == pattern_map.top) {
                pattern_map.src[pattern_map.top] = words[i][j];
                pattern_map.dst[pattern_map.top] = pattern[j];

                pattern_map.top++;
                
            }
        }
        if (j == len) {
            result[*returnSize] = (char *) malloc(sizeof(char) * len);
            strcpy(result[*returnSize], words[i]); 
            (*returnSize)++;
        }
        
    }
    return result;
}
