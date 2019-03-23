# python中有个zip函数的哦

# 这里我们用python2可行。
# python3 可能没有reduce这个函数。

class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """   
        def commonPrefix(s1, s2):
            i = 0
            for a, b in zip(s1,s2):
                if a != b:
                    break 
                i += 1
            return s1[:i]
        return "" if len(strs)==0 else reduce(commonPrefix, strs)	
	
# Solution Two
# 这是java语言。

public String longestCommonPrefix(String[] strs) {
    if(strs == null || strs.length == 0)    return "";
    String pre = strs[0];
    int i = 1;
    while(i < strs.length){
        while(strs[i].indexOf(pre) != 0)
            pre = pre.substring(0,pre.length()-1);
        i++;
    }
    return pre;
}
        
