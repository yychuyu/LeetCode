class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> f(ratings.size(), 1);
        int s=0;
        for(int i = 1; i < ratings.size(); i++)
        {if(ratings[i] > ratings[i - 1])
                f[i] = f[i-1] + 1;}
        for(int i = ratings.size() - 2; i>=0; i--)
        {if(ratings[i] > ratings[i+1])
                f[i] = max(f[i], f[i+1] + 1);}
        for(auto e:f)
            s += e;
        return s;
        
        }
};