/*
接雨水
*/
#include <stdio.h>
int trap(int a[],int n)
{
    int result = 0;//记录结果
    //找寻最高的值/数组位置
    int maxHigh = 0;
    int maxIdx = 0;
    for(int i = 0;i < n; i++)
    {
        if(a[i] > maxHigh){
            maxHigh = a[i];
            maxIdx = i;
        }
    }

    //从左侧到最高位置
    int prevHigh = 0;
    for(int i = 0; i < maxIdx; i++)
    {
        if(a[i] > prevHigh)
        {
            prevHigh = a[i];
        }
        result += (prevHigh - a[i]);
    }
    //从右侧到最高位置
    prevHigh = 0;
    for(int i = n-1; i> maxIdx; i--)
    {
        if(a[i] > prevHigh)
        {
            prevHigh = a[i];
        }
        result += (prevHigh - a[i]);
    }

    return result;
}

int main(int argc, char const *argv[])
{
    int a[] = {2,0,2};
    printf("%d\n",trap(a,sizeof(a)/sizeof(int)));
    int b[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    printf("%d\n",trap(b,sizeof(b)/sizeof(int)));
    return 0;
}
