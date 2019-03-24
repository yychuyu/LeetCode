//words中出现的单词顺序可以以任何次序出现在S中，但是必须连续，而且各个单词只出现一次。
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) 
    {
        vector<int> ret;
        ret.clear();
        map<string, int> Map;
        map<string, int> temp;
        Map.clear();
        temp.clear();
        int slen = s.size();
        int wlen = words.size();

        if(slen == 0 || wlen == 0)
        {
            return ret;//某个为空，返回空
        }

        int perlen = words[0].size();
        if(wlen*perlen >slen)
        {
            return ret;//words长度大于string长度，返回空
        }

        for(int i = 0;i < wlen; ++i)
        {
            Map[words[i]]++;
        }

        for(int i=0;i + perlen*wlen -1 < slen; ++i)
        {
            int j = i;
            temp.clear();
            while (j <= i +wlen*perlen -1)
            {
                temp[s.substr(j,perlen)]++;
                if(Map[s.substr(j,perlen)] < temp[s.substr(j, perlen)])
                {
                    break;
                }
                else
                {
                    j += perlen;
                }
                if(j > i + wlen*perlen -1)
                {
                    ret.push_back(i);
                }
                
            }
        }
        return ret;
    }
};