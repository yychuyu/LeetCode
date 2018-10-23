/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     ：Torres Ng
*   Create Time ：2018/10/22
*
***************************************************************/
/**************************************************************
We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number is higher or lower.

You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):

-1 : My number is lower
 1 : My number is higher
 0 : Congrats! You got it!

Example :

Input: n = 10, pick = 6
Output: 6
***************************************************************/
#include <iostream>

using namespace std;

int number = 1702766719;

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num) {
    if(num < number) {
        return 1;
    } else if(num > number) {
        return -1;
    } else {
        return 0;
    }
}

class Solution {
public:
    int guessNumber(int n) {
        int i=1, j=n;
        while(true) {
            int mid = ((j-i)/2) + i;
            switch(guess(mid)) {
                case 0:
                    return mid;
                case 1:
                    i = mid + 1;
                    break;
                case -1:
                    j = mid - 1;
                    break;
            }
        }
    }
};

int main(void) {
    Solution s = Solution();
    cout << s.guessNumber(2126753390) << endl;
    return 0;
}
