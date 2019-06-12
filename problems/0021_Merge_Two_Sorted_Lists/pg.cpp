class Solution {
    public:
    vector<string> generateParenthesis(int n) {
        vector<string> resultList;
        backTrack(resultList, "", 0, 0, n);
        return resultList;
        
    }
    
    void backTrack(vector<string> &res,string curStr,int open,int close,int max){
        if ( max*2 == curStr.size()){
            res.push_back(curStr);
            return;
        }
        if (open < max)
        backTrack(res, curStr+"(", open+1, close, max);
        if (close < open)
        backTrack(res, curStr+")", open, close+1, max);
    }
};


