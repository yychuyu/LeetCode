#include <iostream>

using namespace std;

class Solution {
public:
    bool isUgly(int num) {
        while(num && num != 1) {
            if(num % 2 == 0) {
                num /= 2;
            } else if(num % 3 == 0) {
                num /= 3;
            } else if(num % 5 ==0) {
                num /= 5;
            } else {
                break;
            }
        }
        if(num == 1) {
            return true;
        } else {
            return false;
        }
    }
};

int main(void)
{
    Solution s = Solution();
    cout << s.isUgly(8) << endl;
    
    return 0;
}
