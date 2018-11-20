#include <stdio.h>
#include <stdlib.h>

int findNthDigit(int n) {
    int i, idx;
    long m, origin, result;
    long h = 1;
    m = 9;
    i = 0;

    while (n > m) {
        h = h * 10;
        i++;
        m = m + (i + 1) * 9 * h;
    }
    m = m - (i + 1) * 9 * h + 1;

    origin = (n - m) / (i + 1) + h;
    idx = i + 1 - (n - m) % (i + 1);

    while (idx > 1) {
        origin = origin / 10;
        idx--;
    }

    return origin % 10;
}

int main()
{
    printf("%d\n", findNthDigit(1000001));
    return 0;
}

