char* addBinary(char* a, char* b) {
    int lena = strlen(a);
    int lenb = strlen(b);
    int lenp = lena>lenb ? lena+2 : lenb+2;
    
    char *pa = a+lena-1, *pb = b+lenb-1;
    char *p = (char*)malloc(lenp*sizeof(char));
    *(p+lenp-1) = '\0';  //end of string, don't forget.
    lenp--;
    int add = 0;
    
    while (lena > 0 && lenb > 0) {
        int temp = (*pa-'0')+(*pb-'0')+add;
        add = temp / 2;
        *(p+lenp-1) = temp%2 + '0';
        pa--;
        pb--;
        lena--;
        lenb--;
        lenp--;
    }
    while (lena > 0) {
        int temp = (*pa-'0')+add;
        add = temp / 2;
        *(p+lenp-1) = temp%2 + '0';
        pa--;
        lena--;
        lenp--;
    }
    while (lenb > 0) {
        int temp = (*pb-'0')+add;
        add = temp / 2;
        *(p+lenp-1) = temp%2 + '0';
        pb--;
        lenb--;
        lenp--;
    }
    *(p+lenp-1) = add+'0';
    
    if (add == 0) p++;
    
    return p;
}
