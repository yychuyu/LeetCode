class Solution {
public:
    string convert(string s, int numRows) {
        if(s.empty() || numRows<=1) return s;
        vector<vector<char>> temp(numRows);
        int ln=0;
        int flag=0;
        for(int i=0; i!=s.size();++i)
        {
            temp[ln].push_back(s[i]);
            if(numRows-1==ln)
            {
                flag=1;
            }
            if(0==ln)
            {
                flag=0;
            }
            if(0==flag)
            {
                ++ln;
            }
            if(1==flag)
            {
                --ln;
            }
        }
        int sum=0;
        string res;
        for(int i=0; i<numRows && sum<s.size();++i)
        {
            for(auto c : temp[i])
            {
                res+=c;
                sum++;
            }
        }
        return res;
    }
};
