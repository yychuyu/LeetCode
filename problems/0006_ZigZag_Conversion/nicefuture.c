#include <stdio.h>
#include <stdlib.h>

char* convert(char* s, int numRows) {
    if (numRows <= 1) return s;

    //get length
    int length = 0;
    while(s[length] != '\0') {
		length++;
	}
	
	//initialize array
	int numBack = numRows - 2;
	int mod = length%(numRows+numBack);
	int extra = mod - numRows;
	extra = (extra > 0) ? extra+1 : 1;
	int column = length/(numRows+numBack)*(numBack+1) + extra;
	char str[numRows][column];
	
	int i = 0, j = 0;
	
	for (i = 0; i < numRows; i++) {
		for (j = 0; j < column; j++) {
			str[i][j] = ' ';
		}
	}
	
	int l = 0, k = 0;
	i = 0, j = 0;
	
	while(l < length) {
		//forward
		for (k = 0; l < length && k < numRows; k++) {
			str[i][j] = s[l];
			i++;
			l++;
		}
		i--;
		//backward
		for (k = 0; l < length && k < numBack; k++) {
			i--;
			j++;
			str[i][j] = s[l];
			l++;
		}
		i--;
		j++;
	}
	
	for (i = 0; i < numRows; i++) {
		for (j = 0; j < column; j++) {
            printf("%c ", str[i][j]);
		}
        putchar('\n');
	}

    char* r = (char*) malloc(sizeof(char)*length+1);
    k = 0;

	for (i = 0; i < numRows; i++) {
		for (j = 0; j < column; j++) {
			if (str[i][j] == ' ') continue;
            r[k] = str[i][j];
            k++;
		}
	}
    r[k] = '\0';
	
	return r;
}

int main(void)
{
    char s[1000] = {};
    int n;
    scanf("%s", s);
    scanf("%d", &n);
	char* r = convert(s, n);
    char c;
    int i = 0;
    while ((c=r[i]) != '\0') {
        printf("%c", c);
        i++;
    }
    putchar('\n');
	
	return 0;
}
