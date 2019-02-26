#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x) {
    if (x < 0) return false;
    int old = x;
    long result = 0;
    
    while (x) {
        result = (result*10) + (x%10);
        x /= 10;
    }
    
    return (result == old) ? true : false;
}

int main(void)
{
	printf("121: %s\n", (isPalindrome(121) == 1 ) ? "true" : "false");
	printf("-121: %s\n", (isPalindrome(-121) == 1 ) ? "true" : "false");
	printf("10: %s\n", (isPalindrome(10) == 1 ) ? "true" : "false");

    return 0;
}
