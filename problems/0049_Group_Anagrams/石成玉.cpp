class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        int index = 0;
        unordered_map<string, int> table;
        
        for(int i=0; i<strs.size(); i++) {
            string word = strs[i];
            sort(word.begin(), word.end());
            if(table.count(word) == 0) {
                table[word] = index;
                result.push_back(vector<string>());
                result[index].push_back(strs[i]);
                index++;
            }
            else {
                result[table[word]].push_back(strs[i]);
            }
        }
        
        return result;
    }
};
