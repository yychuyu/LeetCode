#include <stdio.h>
#include <stdbool.h>

#define NUM 8

bool isUgly(int num)
{
	int i = 0;

	for (i = 2; i < 6 && num; i++) {
		while (num % i == 0)
			num /= i;
	}
	return num == 1;
}

int main()
{
	printf("number %d %s ugly number.\n", NUM, isUgly(NUM)?"is":"is not");
}
