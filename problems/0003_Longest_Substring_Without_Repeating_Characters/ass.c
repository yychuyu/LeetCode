#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define Cnum 6
#define Marx 11

int lengthOfLongestSubstring(char *s);
int main(void)
{
	srand((unsigned int)time(0));
	char s[Marx];
	for(int i=0;i<Marx-1;i++)
	{
		s[i] = 'a' + (rand()%Cnum);
	}
	s[Marx] = '\0';
	printf("%s\n",s);
	int sub = lengthOfLongestSubstring(s);
	printf("%d\n",sub);
	return 0;
}
int lengthOfLongestSubstring(char* s) {
        if(*s=='\0')  return 0;  //判断输入是否为空串
        char *S1=s ,*S2=s,*S3=s; //S1表示无重合字符串起点，S2表示无重合字符串终点，S3表示待检测点
        int sum = 1 , tmp = 1;   //sum记录最长无重合子串长度，tmp表示临时长度 
        int flag ,ps;		 //flag标记发生重合的位置，是S1--S2之间还是S2的位置对应不同操作
        S3++;
        while(*S3!='\0')
        {
                flag = 0,ps=0;
                char *p = S1;
                for( ;*S1 != *S2;++S1)
                {   
                        ++ps;
                        if(*S1 == *S3)
                        {
                                flag =1;
                                tmp =tmp-ps+1;
                                ++S1;
                                S2 = S3;
                                break;
                        }
                }
        if((*S2 != *S3)&&(flag==0))
        {
                tmp++;
                S1=p;
                S2=S3;
        }
        else if((*S2 == *S3)&&(flag==0))
        {
            tmp = 1;
            ++S1;
            S2=S3=S1;
        }
        if(sum < tmp)
                sum = tmp;
        
        S3++;
        }
        return sum;
}
