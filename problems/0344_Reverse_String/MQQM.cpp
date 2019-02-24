/*
  题目：
  编写一个函数，其作用是将输入的字符串反转过来。
*/
class Solution {
public:
    string reverseString(string s) {
        if(s.empty()){
            return s;
        }
                
        int left = 0;
        int right =  s.size() - 1;        
        while(left < right){
            swap(s[left], s[right]);
            left++;
            right--;
        }
        
        return s;
    }
};
