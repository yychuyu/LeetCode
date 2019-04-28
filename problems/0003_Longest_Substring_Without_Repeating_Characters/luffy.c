/************************************************************************
算法：
1.统计出每一个不同字符串的长度，每一个长度用数组max[k]来表示，扫描用循环来遍历，第二层从每个不同子字符串的开头遍历。
2.进行比较，得出最长长度maximum，输出。
时间复杂度：O(n平方),时间复杂度较高
**************************************************************************/
#include <stdio.h>
#include <string.h>
#include"stdlib.h"
int lengthOfLongestSubstring(char* s) 
{
	int maximum;
	int lenght;
	int lenght_array[100]={0};
	int k = 0;
	lenght = strlen(s);
	for(int i = 0;i < lenght;i++)
	{
		if(s[i]!=s[i+1])
		{
			lenght_array[k]++;
		}	
		else
		{
			k++;
		}
	}
	
	for(int i = 0;i < k;i++)
	{
		if(lenght_array[i]>lenght_array[i+1])
		{
			maximum = lenght_array[i];
		}
	}
	
    return maximum;
}
void main(void)
{
        int lenght;
	char* s="pwwkewwwabcdddacdefgvdffff";
        lenght=lengthOfLongestSubstring(s);
        printf("a的值为：%d\n",lenght);
	system("pause");
}

