/* 
    Palindrome Number
        Determine whether an integer is a palindrome. 
        An integer is a palindrome when it reads the same backward as forward.

--------------------------------------------------------------------------------------------
|  Runtime: 12 ms, faster than 92.09% of C++ online submissions for Palindrome Number.     |
|  Memory Usage: 8.2 MB, less than 65.36% of C++ online submissions for Palindrome Number. |
--------------------------------------------------------------------------------------------

*/

class Solution {
public:
    bool isPalindrome(int x) {
        /* 排除小于0，如整10、100、1000....的情况 */
        if(x < 0 || (x % 10 == 0 && x != 0))
        {
            return false;
        }
        
        int changeData = 0;
        while(x > changeData)
        {
            changeData *= 10;
            changeData += x % 10;
            x /= 10;
        }
        
        /* 奇数情况与偶数情况 */
        bool res = ((changeData/10 == x) || (changeData == x))?true:false;
        return res;

    }
};
