
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
public:
    int countPrimes(int n) {
        if(n < 3) return 0;
        int count = 0;
        vector<bool> vec(n, true);
        for(int i = 2; i*i < n; i++) {
            if(!vec[i]) continue;
            for(int j = i*i; j < n; j+=i) {
                vec[j] = false;
            }
        }
        for(int i = 2; i < n; i++) {
            if(vec[i]) count++;
        }
        return count;
    }
};
