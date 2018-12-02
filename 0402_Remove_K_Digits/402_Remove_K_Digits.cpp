class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> stacknum;
        string result = "";
        if(num.size()<=k){
            return "0";
        }
        stacknum.push_back(num[0]);
        for(int i = 1; i < num.size(); i++){
            while(k&&num[i] < stacknum.back()){
                stacknum.pop_back();
                k--;
            }
            stacknum.push_back(num[i]);
        }
        while(k&&!stacknum.empty()){
            stacknum.pop_back();
            k--;
        }
        int i = 0;
        for(i = 0; i < stacknum.size();i++){
            if(stacknum[i]=='0'){
                continue;
            }
            else{
                break;
            }
        }
        if(i == stacknum.size()){
            return "0";
        }
        for(; i < stacknum.size(); i++){
            result+=stacknum[i];
        }
        return result;
    }
    
};