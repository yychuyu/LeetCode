void swap(char *a, char *b) {
    char c = *a;
    *a = *b;
    *b = c;
}

char * reverseOnlyLetters(char * S){
    int len = strlen(S);
    int i = 0, j = len-1;
    
    while (i < j) {
        while (i < j && !((S[i]>='a'&&S[i]<='z') || (S[i]>='A'&&S[i]<='Z'))) {
            i++;
        }
        while (i < j && !((S[j]>='a'&&S[j]<='z') || (S[j]>='A'&&S[j]<='Z'))) {
            j--;
        }
        swap(&S[i], &S[j]);
        i++;
        j--;
    }
    
    return S;
}


