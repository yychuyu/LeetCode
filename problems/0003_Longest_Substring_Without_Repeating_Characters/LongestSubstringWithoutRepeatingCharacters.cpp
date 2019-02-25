class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if(s.empty()){  /*首先判断是否为空*/
            return 0;  
        }  
        int i = 0, j = 1;                   /*i表示子串头部，j表示子串尾部*/
        int len = 0;  		                /*子串长度*/
        while(j < s.size()&& i < s.size()){                /*总字符串的长度*/
            string t = s.substr(i, j - i);  /*substr()函数截取i~j子串:Sij*/
            int pos = t.find(s.at(j));      /*发现字符串的下标*/
            if (pos < t.size()){            /*保证pos在总字符串之内,避免重复*/
                if (len < j - i){           /*如果发现子串比之前的长度长，就替换掉原来的长度*/
                    len = j - i;            
                }  
                i =  i + pos + 1;           /*子串头部位置要更新，向后移一位*/
            }  
            ++j; 
        }  
        if (len < j - i){                   /*跳出循环记得保存结果*/
            len = j - i;                    /* 更新长度 */
        }  
        return len; 
    }
};
