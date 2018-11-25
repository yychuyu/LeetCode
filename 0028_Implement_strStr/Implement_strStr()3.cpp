//KMP算法
/*
  题目：
  实现 strStr() 函数。
  给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。
  
  说明:
  当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
  对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
  
  参考：
  https://www.cnblogs.com/ganganloveu/p/3753981.html
  https://blog.csdn.net/v_july_v/article/details/7041827
*/
class Solution {
public:
    void getNext(string& needle, int next[]){
        int len=needle.size();
        next[0]=-1;
        int i=0;
        int j=-1;
        
        while(i<len-1){
            if(j==-1 || needle[i]==needle[j]){
                i++;
                j++;
                next[i]=j;
            }else{
                j=next[j];
            }
        }
    }
    
    int strStr(string haystack, string needle) {
        if( needle.empty() ){//needle为空
            return 0;
        }
               
        int len1=haystack.size(), len2=needle.size();
        int* next=new int[len2];
        getNext(needle,next);        
       
        int i=0, j=0;
        while(i<len1 && j<len2){
            if(j==-1 || haystack[i]==needle[j]){
                i++;
                j++;
            }else{
                j=next[j];
            }            
        }
        
        if(j==len2){
            return i-len2;
        }else{
            return -1;
        }    
    }
};
