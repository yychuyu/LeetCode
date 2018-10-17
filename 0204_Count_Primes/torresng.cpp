
/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     ：Torres Ng
*   Create Time ：2018/10/16
*
***************************************************************/
/**************************************************************
ount the number of prime numbers less than a non-negative number, n.

Example:

Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
***************************************************************/
class Solution {
    bool isPrime(int n) {
        int i;
        for(i = 2; i <= sqrt(n); i++) {
            if(n%i == 0) {
                return false;
            }
        }
        return true;
    }

public:
    int countPrimes(int n) {
        size_t count = 0;
        for(int i = 2; i < n; i++) {
            if(isPrime(i)) count++;
        }
        return count;
    }
};
