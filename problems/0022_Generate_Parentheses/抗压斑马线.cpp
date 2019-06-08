/*
22. Generate Parentheses [Medium]
    Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
    For example, given n = 3, a solution set is:
        [
        "((()))",
        "(()())",
        "(())()",
        "()(())",
        "()()()"
        ]
    ------------------------------------------------------------------------------------------------
    |    Runtime: 8 ms, faster than 87.04% of C++ online submissions for Generate Parentheses.     |
    |   Memory Usage: 17.4 MB, less than 28.91% of C++ online submissions for Generate Parentheses.|
    ------------------------------------------------------------------------------------------------
*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        recursiveAchieve(&ans, "", 0, 0, n);
        return ans;
    }
    
    void recursiveAchieve(vector<string> *str, string border, int start, int end, int count)
    {
        if  (border.length() == count * 2)
        {
            str->push_back(border);
            return;
        }
        
        if (start < count)
        {
            recursiveAchieve(str, border+"(", start + 1, end, count);
        }
        
        if (end < start)
        {
            recursiveAchieve(str, border+")", start, end + 1, count);
        }
    }
};

