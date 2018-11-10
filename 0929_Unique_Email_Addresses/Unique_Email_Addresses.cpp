class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> unique;
        for(auto str:emails){
            string result;
            bool plu=false;
            for(auto it = str.cbegin();it!=str.cend();it++){
                if(*it=='+' && !plu){
                    plu=true;
                }
                else if(*it=='@'){ 
                    result +=str.substr(distance(str.cbegin(),it));
                    break;
                }
                else if(*it!='.' && !plu)
                    result.push_back(*it);
            }
            unique.insert(result);
        }
        return unique.size();
    }
};