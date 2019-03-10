void reverseString(char* s, int sSize) {
    for (int i=0; i < sSize/2; i++) {
        char temp = s[i];
        s[i] = s[sSize-1-i];
        s[sSize-1-i] = temp;
    }
}
