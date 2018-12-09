/*
using C++ STL
*/
class Solution {
public:
    string reverseOnlyLetters(string S) {
        string Q;
        for(auto ch:S){
            if(isalpha(ch))
                Q.push_back(ch);
        }
        reverse(Q.begin(),Q.end());
        auto it = Q.begin();
        for(auto& ch:S){
            if(isalpha(ch)){
                ch = *it++;
            }
        }
        return S;
    }
};
/*
using two pointer
*/
class Solution {
public:
    string reverseOnlyLetters(string S) {
        int i=0,j = S.size()-1;
        while(i<j){
            while(!isalpha(S[i])) i++;
            while(!isalpha(S[j])) j--;
            if(i<j) swap(S[i++],S[j--]);
        }
        return S;
    }
};