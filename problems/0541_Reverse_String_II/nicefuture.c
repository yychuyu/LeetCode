void reverse(char* s, int low, int k) {
    for (int i=low; i<(low+k/2); i++) {
        char t = s[i];
        s[i] = s[low+k-1-(i-low)];
        s[low+k-1-(i-low)] = t;
    }
}

char* reverseStr(char* s, int k) {
    int len = strlen(s);
    int i;
    for (i=0; (i+2*k)<len; i+=2*k) {
        reverse(s, i, k);
    }
    if (len-i > k) reverse(s, i, k);
    else reverse(s, i, len-i);
    
    return s;
}
