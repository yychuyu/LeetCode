#include <string.h>
#include <assert.h>
#include <stdint.h>
#include <stdio.h>

#define MAX_LEN  256

uint32_t isUnique(const char* p,uint32_t len)
{
    assert(len < 256);
    int str[MAX_LEN] = {0};

    uint32_t loop = 0;
    for(;loop < len;loop++)
    {
        str[p[loop]] += 1;
        printf("%d\t",str[p[loop]]);
    }

    for(loop=0;loop<MAX_LEN;loop++)
    {
        if(str[loop] > 1)
        {
            return 0;
        }
    }
    return len;
}

int lengOfLongestSubstring(const char* p)
{
    uint32_t outterloop = 0,innerloop=0;
    uint32_t len = strlen(p);
    uint32_t max = 1;
    uint32_t tmp = 0;
    for(;outterloop < len;outterloop++)
    {
        for(innerloop=outterloop+1;innerloop < len; innerloop++)
        {
            tmp = isUnique(p+outterloop,innerloop-outterloop+1);
            if(tmp == 0)
                break;
            max = max>tmp?max:tmp;
        }
    }
    return max;
}

int main()
{
    char p[] = "pwwkew";
    char q[] = "abcabc";
    printf("p max substring:%d\n",lengOfLongestSubstring(p));
    printf("q max substring:%d\n",lengOfLongestSubstring(q));

    return 0;
}
