class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> ans;
        string sub_ans;
        traverse(ans, sub_ans, S, 0);
        
        return ans;
    }
    
    void traverse(vector<string> &ans, string &sub_ans, string &S, int i) {
        if(i < S.size()) {
            sub_ans.push_back(S[i]);
            traverse(ans, sub_ans, S, i + 1);
            sub_ans.pop_back();
            if(S[i] >= 'a' && S[i] <= 'z'){
                sub_ans.push_back(S[i] - 32);
                traverse(ans, sub_ans, S, i + 1);
                sub_ans.pop_back();
            }
            else if(S[i] >= 'A' && S[i] <= 'Z'){
                sub_ans.push_back(S[i] + 32);
                traverse(ans, sub_ans, S, i + 1);
                sub_ans.pop_back();
            }
        }
        else
            ans.push_back(sub_ans);
    }
};
