char* reverseVowels(char* s) {
    int length = strlen(s);
    int i=0, j=length-1;
    
    while (i < j) {
        while (i < j && //大前提不能忘，不然越界根本停不下来
               s[i]!='a' && s[i]!='e' && s[i]!='i' && s[i]!='o' && s[i]!='u' && 
               s[i]!='A' && s[i]!='E' && s[i]!='I' && s[i]!='O' && s[i]!='U') i++;  //加上大写
        while (i < j && 
               s[j]!='a' && s[j]!='e' && s[j]!='i' && s[j]!='o' && s[j]!='u' && 
               s[j]!='A' && s[j]!='E' && s[j]!='I' && s[j]!='O' && s[j]!='U') j--;
        if (i < j) {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;  //换完就得往前走，不然会停在这一直循环
            j--;
        }
    }
    
    return s;
}
