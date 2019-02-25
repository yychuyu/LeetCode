/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     ：Torres Ng
*   Create Time ：2018/12/04
*
***************************************************************/
/**************************************************************
Given an array of 4 digits, return the largest 24 hour time that can be made.

The smallest 24 hour time is 00:00, and the largest is 23:59.  Starting from 00:00, a time is larger if more time has elapsed since midnight.

Return the answer as a string of length 5.  If no valid time can be made, return an empty string.

 

Example 1:

    Input: [1,2,3,4]
    Output: "23:41"

Example 2:

    Input: [5,5,5,5]
    Output: ""

 

Note:

    1. A.length == 4
    2. 0 <= A[i] <= 9
***************************************************************/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        int max;
        string res;
        perm(A, 0, 4, max);
        cout << max << endl;
        for(int i = 0; i < A.size(); i++) {
            res = to_string(max % 10) + res;
            if(i == 1) res = ":" + res;
            max /= 10;
        }

        return res;
    }

private:
    void perm(vector<int>&A, int start, int end, int &max) {
        if(start == end) {
            int res = A[0] * 1000 + A[1] * 100 + A[2] * 10 + A[3];
            if(res <= 2359 && res > max) max = res;
        }
        for(int i = start; i < end; i++) {
            swap(A[start], A[i]);
            perm(A, start + 1, end, max);
            swap(A[i], A[start]);
        }
    }
};

int main(void) {
    Solution s = Solution();
    vector<int> vec {1,2,3,4};
    cout << "Input: [1,2,3,4]" << endl;
    cout << "Output: " << s.largestTimeFromDigits(vec) << endl;
    
    vec = {5,5,5,5};
    cout << "Input: [5,5,5,5]" << endl;
	cout << "Output: " << s.largestTimeFromDigits(vec) << endl;
    
    vec = {0,0,0,0};
    cout << "Input: [0,0,0,0]" << endl;
    cout << "Output: " << s.largestTimeFromDigits(vec) << endl;

    return 0;
}

