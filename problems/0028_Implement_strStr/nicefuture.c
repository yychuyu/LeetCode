//KMP
void getNext(int len, int* next, char* needle)
{
    int j = 0, k = -1;
    next[0] = -1;
    while (j < len-1) {
        if (k == -1 || needle[j] == needle[k]) {
            j++;
            k++;
            if (needle[j] != needle[k]) {
                next[j] = k;
            } else {
                next[j] = next[k];
            }
        } else {
            k = next[k];
        }
    }
}

int strStr(char* haystack, char* needle) {
    int hlen = strlen(haystack);
    int nlen = strlen(needle);

    if (nlen == 0) {
        return 0;
    }
    if (hlen == 0 || hlen < nlen) {
        return -1;
    }
    int next[nlen];
    getNext(nlen, next, needle);
    
    int i = 0, j = 0;
    while (i < hlen && j < nlen) {
        if (j == -1 || haystack[i] == needle[j]) {
            i++;
            j++;
        } else {
            j = next[j];
            if (hlen-i+1 < nlen-j+1) {
                break;
            }
        }
    }
    if (j == nlen) {
        return i-j;
    }
    return -1;
}
