class Solution {
    vector<int> getPatternVec(string pattern)
    {
        string chars;
        vector<int> ans;
        for(char x : pattern)
        {
            if(chars.find_first_of(x) == chars.npos)
            {
                chars.push_back(x);
            }
        }

        for(char x : pattern)
        {
            ans.push_back(chars.find_first_of(x));
        }

        return ans;
    }

public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
         vector<string> ans;
        vector<int> patternVec = getPatternVec(pattern);
        for(size_t i = 0; i < words.size(); ++i)
        {
            if(getPatternVec(words[i]) == patternVec)
            {
                ans.push_back(words[i]);
            }
        }

        return ans;
    }
};