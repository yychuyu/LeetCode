/*  DFS
    "23"
    root                        
                /          |         \
     0         a           b          c
             / | \       / | \       / | \ 
     1      d  e  f     d  e  f     d  e  f
            
*/

/*
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.length() == 0) return ans;
        
        vector<vector<char>> dict(10);
        dict[0] = {};
        dict[1] = {};
        dict[2] = {'a', 'b', 'c'};
        dict[3] = {'d', 'e', 'f'};
        dict[4] = {'g', 'h', 'i'};
        dict[5] = {'j', 'k', 'l'};
        dict[6] = {'m', 'n', 'o'};
        dict[7] = {'p', 'q', 'r', 's'};
        dict[8] = {'t', 'u', 'v'};
        dict[9] = {'w', 'x', 'y', 'z'};
        
        string cur;
        dfs(digits, dict, 0, cur, ans);
        
        return ans;
    }
    
    
private:
    void dfs(const string &digits, const vector<vector<char>> &dict,
            int l, string &cur, vector<string> &ans)
    {
        if (l == digits.length())
        {
            ans.push_back(cur);
            return;
        }
        
        for (auto &ch : dict[digits[l] - '0'])
        {
            cur.push_back(ch);
            dfs(digits, dict, l + 1, cur, ans);
            cur.pop_back();
        }
    }
};
*/



/*
    BFS
*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) return {};
        
        vector<vector<char>> dict(10);
        dict[0] = {};
        dict[1] = {};
        dict[2] = {'a', 'b', 'c'};
        dict[3] = {'d', 'e', 'f'};
        dict[4] = {'g', 'h', 'i'};
        dict[5] = {'j', 'k', 'l'};
        dict[6] = {'m', 'n', 'o'};
        dict[7] = {'p', 'q', 'r', 's'};
        dict[8] = {'t', 'u', 'v'};
        dict[9] = {'w', 'x', 'y', 'z'};
        
        vector<string> ans = {""};
        for (const char &digit : digits)
        {
            vector<string> tmp;
            for (const string &cur: ans)
            {
                for (const char &c: dict[digit - '0'])
                {
                    tmp.push_back(cur + c);
                }
            }
            
            ans.swap(tmp);
        }
         
        return ans;
    }
};
