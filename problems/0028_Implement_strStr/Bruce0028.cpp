// 第28题 两个字符串进行匹配。


// Solution one： 暴力破解


class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size();
        int n = needle.size();
        for(int i = 0; i <= m-n; i ++)
        {
            int j;
            for(j = 0; j < n; j ++)
            {
                if(haystack[i+j] != needle[j])
                    break;
            }
            if(j == n)
                return i;
        }
        return -1;
    }
};


// 没懂啊啊啊啊啊


// Solution Two ，KHP法（看黄片法）
// https://www.cnblogs.com/ganganloveu/p/3753981.html

// 小插曲：  KHP详解： July，湖南娄底人，于2010年10月11日开始在CSDN上写博（搜索：结构之法，进入本博客），博客专注面试、算法、机器学习。2011年毕业于东华理工，2015年正式创业，任：七月在线创始人兼CEO，公司官网：七月在线
// https://blog.csdn.net/v_july_v/article/details/7041827

class Solution {
public:
    int strStr(char *haystack, char *needle) {
        int hlen = strlen(haystack);
        int nlen = strlen(needle);
        int* next = new int[nlen];
        getNext(needle, next);
        int i = 0;
        int j = 0;
        while(i < hlen && j < nlen)
        {
            if(j == -1 || haystack[i] == needle[j])
            {// match current position, go next
                i ++;
                j ++;
            }
            else
            {// jump to the previous position to try matching
                j = next[j];
            }
        }
        if(j == nlen)
        // all match
            return i-nlen;
        else
            return -1;
    }
    void getNext(char *needle, int next[])
    {// self match to contruct next array
        int nlen = strlen(needle);
        int j = -1;     // slow pointer
        int i = 0;      // fast pointer
        next[i] = -1;    //init next has one element
        while(i < nlen-1)
        {
            if(j == -1 || needle[i] == needle[j])
            {
                j ++;
                i ++;           //thus the condition (i < nlen-1)
                next[i] = j;    //if position i not match, jump to position j
            }
            else
            {
                j = next[j];    //jump to the previous position to try matching
            }
        }
    }
};

