/** n = 3                              |
                                       (
                            /                    \
                          ((                      ()
                        /     \                   | 
                     (((      (()                ()(      
                      |     /    \            /        \
                   ((()))  (()(  (())      ()((       ()()
                            |      |        |           |
                         (()())  (())()   ()(()       ()()(  
                                            |           |
                                          ()(())      ()()()
                    
*/


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string cur = "";
        helper(n, cur, ans, 0, 0);
        
        return ans;
    }
    
private:
    // n：n对括号，
    // cur:当前字符串的情况，
    // ans:满足条件的解的集合，
    // left:左括号的个数，
    // right:右括号的个数
    void helper(int n, string cur, vector<string> &ans, int left, int right) {
        if (right == n) {
            ans.push_back(cur);
            return;
        }
        
        if (left < n) {
            helper(n, cur + '(', ans, left + 1, right);
        }
        
        if (left > right) {
            helper(n, cur + ')', ans, left, right + 1);
        }
    }
};
