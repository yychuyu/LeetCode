
/**特别说明，该解法是最简单同时也是效率较低的解法，后面补充其他解法*/

/*判断是否有重复的字符,如果没有，返回字符长度，如果有，返回0*/
unsigned int isallUnique(const char *string,unsigned int len)
{
    if(len > 256)
    {
        return 0;
    }
    int str[256] = {0};
    unsigned int loop = 0;
    
    for(;loop < len;loop++)
    {
        str[string[loop]]+=1;
    }
    for(loop = 0;loop < 256;loop++)
    {
        if(str[loop] >1)
            return 0;
    }
    
    return len;
    
}

int lengthOfLongestSubstring(char* s) {
    if(NULL == s)
    {
        return 0;
    }
    if(0 == strcmp("",s))
    {
        return 0;
    }
    unsigned int len = strlen(s);
    unsigned int outLoop = 0;
    unsigned int loop = 0;
    int max = 1;
    unsigned int temp = 0;
    for(;outLoop < len;outLoop++)
    {
 
        for(loop=outLoop+1;loop < len;loop++)
        {
 
                temp = isallUnique(s+outLoop,loop-outLoop+1);
                if(0 == temp)
                    break;
               max=max>temp?max:temp;
        }
        
    }
    return max;
}
