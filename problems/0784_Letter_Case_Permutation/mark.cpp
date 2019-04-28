//dfs遍历，如果如果是数字跳过，是字母分成两种情况传递给子问题（在当前情况下不断深度遍历）
//time:O(2^n)

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        
        vector<string> res;
        dfs(res,S,0);
        return res;
    }
    
    
    void dfs(vector<string>& res,string& s,int p){
        if(p == s.size()) {
            res.push_back(s);    // 遍历终止条件
           // return ;
        }
        
        if(s[p] >= '0' && s[p] <= '9')  //数字情况 
            dfs(res,s,p+1);                       
        else if(s[p] >= 'a' && s[p] <= 'z'){   // 小写字母，修改成大写字母
            dfs(res,s,p+1);                   
            s[p] += 'A'-'a';
            dfs(res,s,p+1);              // 修改后继续dfs
        }
        else if(s[p] >= 'A' && s[p] <= 'Z'){   // 大写字母情况
            dfs(res,s,p+1);
            s[p] += 'a'-'A';
            dfs(res,s,p+1);
        }
    }
};
