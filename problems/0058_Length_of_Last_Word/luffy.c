
#include <stdio.h>
#include <string.h>
#include"stdlib.h"
int lengthOfLastWord(char* s) {
    int len = 0;
    char *c = s;

    while (*c != '\0') {
        if (*c != ' ') {
            len++;
        } else if (*c == ' ' && (*(c+1) != ' ' && *(c+1) != '\0')){
            len = 0;
        }
        c++;
    }

    return len;
}

void main(void)
{
        int lenght;
		char* s="pww keww wabcdddacde fgvdffff";
        lenght=lengthOfLastWord(s);
        printf("a的值为：%d\n",lenght);
		system("pause");
}

