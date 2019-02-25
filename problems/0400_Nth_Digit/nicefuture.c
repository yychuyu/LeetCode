#include <stdio.h>
#include <math.h> 

int main(void)
{
    int n;
    scanf("%d", &n);
    printf("%d\n", findNthDigit(n));
}

int findNthDigit(int n)
{
    if (n < 10) return n;

    int digit = 0;
    while (n > 0) {
        n -= (int)(9*pow(10, digit)*(digit+1));
        digit++;
    }
    n += (int)(9*pow(10, digit-1)*digit);  //���ֵĸ���

    int place = (n % digit);  //����������λ
    place = (place == 0) ? digit : place;
    place = digit - place;

    int number = ((n-1) / digit) + 1;  //�����ڵ�ǰ���ֶεڼ�������


    number %= (int)(pow(10, place) * 10);
    number = (number == 0) ? (int)pow(10, place+1) : number;

    number = (number-1) / (int)pow(10, place);
    if (place == (digit-1)) number++;  //���λû��0

    return number;
}
