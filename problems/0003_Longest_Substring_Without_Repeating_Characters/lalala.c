#include<stdio.h>
#include<string.h>

/************************************************************************
算法：
1.统计出每一个不同字符串的长度，每一个长度用数组max[k]来表示，扫描用循环来遍历，第二层从每个不同子字符串的开头遍历。
2.进行比较，得出最长长度maximum，输出。
时间复杂度：O(n平方),时间复杂度较高
**************************************************************************/
int lengthOfLongestSubstring(char* s) {
	int length = strlen(s);
	int max[100]= {0},i,j,k=0,m,maximum=0,l=0;
	for (i=0;i<length;i++){
		for(j=l;j<i;j++){
			if(*(s+j) != *(s+i))
				max[k]++;
			else
				k++;
				l=i;
		}
	}
	for(m=0;m<=k;m++){
		if(max[m]>=maximum)
			maximum = max[m];
	}
	return maximum;
}
void main(void)
{
	int a;
	char* s="pwwkewwwabcdddacdefgg";
	a=lengthOfLongestSubstring(s);
	printf("a的值为：%d\n",a);
}
