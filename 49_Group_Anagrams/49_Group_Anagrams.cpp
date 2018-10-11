class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        if(strs.empty()){
            return result;
        }
        
        int idx=0;
        unordered_map<string,int> m;
        
        for(int i=0;i<strs.size();i++){
            string s=strs[i];
            sort(s.begin(),s.end());
            
            if(m.find(s) == m.end()){
                m[s] = idx;
                idx++;
                result.push_back(vector<string>{});
            }
            
            result[m[s]].push_back(strs[i]);
        }     
        
        return result;
    }
};
