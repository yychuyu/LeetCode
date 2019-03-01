/*
  题目：
  找出来自同一键盘行的字符串
*/
class Solution {
public:     
    set<char> v1={'q','w','e','r','t','y','u','i','o','p',
                 'Q','W','E','R','T','Y','U','I','O','P'};  
    set<char> v2 ={'a','s','d','f','g','h','j','k','l',
                  'A','S','D','F','G','H','J','K','L'};
    set<char> v3 ={'z','x','c','v','b','n','m',
                  'Z','X','C','V','B','N','M'};
    
    static bool isAllCharIn(set<char>& v,string& s){
        for(int i=0;i<s.size();i++){
            if( v.find(s[i])==v.end() ){
                return false;
            }
        }        
        return true;
    }
    
    vector<string> findWords(vector<string>& words) {
        vector<string> rst;    
        
        for(int i=0; i<words.size(); i++){
            string s=words[i];
            if( isAllCharIn(v1,s) ){
                rst.push_back(s);
                continue;
            }
            if( isAllCharIn(v2,s) ){
                rst.push_back(s);
                continue;
            }
            if( isAllCharIn(v3,s) ){
                rst.push_back(s);
                continue;
            }                        
        }        
        
        return rst;
    }
};
