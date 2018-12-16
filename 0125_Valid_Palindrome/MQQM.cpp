/*
  题目：
  给定一个字符串，验证它是否是回文串(前后对称)。只考虑字母和数字。
*/
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
       while (left < right){
           if( !isAlphaNum(s[left]) ){
               ++left;
           }else if(!isAlphaNum(s[right])) {
               --right;
           }else if ( (s[left] + 32 - 'a') % 32 != (s[right] + 32 - 'a') % 32 ){
               return false;
           }else {				
               ++left; --right;			
           }
		    }
    
        return true;
    }
    bool isAlphaNum(char ch){
        if(ch >= 'a' && ch <= 'z')  return true;
        if(ch >= 'A' && ch <= 'Z')  return true;
        if(ch >= '0' && ch <= '9')  return true;
        
        return false;
    }
};
