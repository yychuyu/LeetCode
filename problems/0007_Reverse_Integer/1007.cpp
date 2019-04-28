
class Solution {
public:
    int reverse(int x) {
        string s = std::to_string(x);
        if(s[0] == '-')
            std::reverse(s.begin()+1,s.end());
        else
            std::reverse(s.begin(),s.end());
        long long int temp = stoll(s);
        if(temp>2147483647 || temp<-2147483648)
            return 0;
        return (int)temp;
    }
this file is added by shyshy
