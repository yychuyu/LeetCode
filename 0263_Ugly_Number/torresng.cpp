#include <iostream>

using namespace std;

class Solution {
public:
    bool isUgly(int num) {
        if(num <= 0) {
            return false;
        }
        while(num % 5 == 0) {
            num /= 5;
        }
        while(num % 3 == 0) {
            num /= 3;
        }
        while(num % 2 == 0) {
            num /= 2;
        }
        return num == 1;
    }
};

int main(void)
{
    Solution s = Solution();
    cout << "isUgly(4): " << boolalpha << s.isUgly(4) << endl;
    cout << "isUgly(8): " << boolalpha << s.isUgly(8) << endl;
    cout << "isUgly(14): " << boolalpha << s.isUgly(14) << endl;
    
    return 0;
}
