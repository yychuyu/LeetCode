class Solution {
public:
    int romanToInt(string s) {
        const map<char,int> roman{{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int sum=0;
        auto it = s.cbegin();
        while(it != s.cend()){
            if( (it+1 !=s.cend()) && roman.at(*it) < roman.at(*(it+1))){
                sum+=roman.at(*(it+1))-roman.at(*it);
                it+=2;
            }
            else{
                sum+=roman.at(*it);
                it++;
            }
        }
        return sum;
    } 
};