int lengthOfLongestSubstring(char* s) {
    unsigned char array[200] = {0};
    unsigned char num = 0;    
    unsigned char len = 0;
    unsigned char maxLen = 0;
    unsigned char i = 0;
    while(*(s+i) != '\0')
    {
        num = *(s+i);
        i++;
        if(array[num]==0)
        {
            len++;
            array[num] = 1;
        }
        else 
        {
           
            len = 0;
            memset(array,0,200);
            s++;
            i=0;
        }
        
        if(len > maxLen)
        {
                maxLen = len;
        }
    }
    
    return maxLen;
}