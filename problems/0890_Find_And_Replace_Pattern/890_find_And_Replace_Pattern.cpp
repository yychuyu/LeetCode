class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        int n = words.size();
        
        for(int i=0; i<n; i++){
            if(isPattern(words[i], pattern)){
                ans.push_back(words[i]);
            }else{
                ;
            }
        }
        return ans;
    }

bool isPattern(string s, string t){
        int m = s.size();
        int n = t.size();
        
        if(m != n)
            return false;
        
        map<char, char> mp1;
        map<char, char> mp2;
        
        for(int i=0; i<m; i++){
            map<char, char>::iterator it;
            
            if(mp1.find(s[i]) != mp1.end()){
                if(mp1[s[i]] != t[i]){
                    return false;
                }    
            }else{
                mp1[s[i]] = t[i];
            }
        }
 
        for(int i=0; i<n; i++){
            map<char, char>::iterator it;
            
            if(mp2.find(t[i]) != mp2.end()){
                if(mp2[t[i]] != s[i]){
                    return false;
            }    
            }else{
               mp2[t[i]] = s[i];
            }
        }
        
        return true;

    }
};