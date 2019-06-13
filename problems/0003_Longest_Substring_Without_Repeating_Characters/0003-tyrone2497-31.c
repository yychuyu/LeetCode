int lengthOfLongestSubstring(char * s){
    char *begin = s, *cursor_char = s, *temp1 = begin;
    char *sub_string = NULL;
    int count = 0, ret_count = 0;
    
    if (*s) {
        count = 1;
        ret_count = 1;
    }

    while (*begin && *cursor_char) {
        /* 找出不重复字符的个数 */
        while (*temp1 != *cursor_char) {
            count ++;
            temp1 ++;
        }
     
        if (count > ret_count)
            ret_count = count;
        
        if (temp1 == cursor_char) {
            /* 当比较的字符和光标字符相同的时候，此时将光标字符往后移动，然后再从头开始计算 

*/
            cursor_char ++;
        } else {
            /* 当首位字符往后移动的时候，光标字符也相应的往后移动，然后再从头开始计算 */
            begin ++;
            cursor_char = begin;
        }
       
        /* 初始化temp1和count */
        temp1 = begin;
        count = 1;
    }
    
    return ret_count;
}
