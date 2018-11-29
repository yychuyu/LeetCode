//26进制转10进制
class Solution {
public:
    int titleToNumber(string s) {
        int result = 0; 
        for(auto ch:s){
            result = result*26 + ch-'A'+1;
        }
        return result;
    }
};