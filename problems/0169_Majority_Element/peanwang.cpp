class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> M;
        for(auto i:nums)
            M[i]++;
        pair<int,int> max = {-1,-1};
        for(auto p:M){
            if(max.second < p.second){
                max = p;
            }
        }
        return max.first;
    }
};
