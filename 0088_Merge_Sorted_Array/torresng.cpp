/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     ：Torres Ng
*   Create Time ：2018/11/18
*
***************************************************************/
/**************************************************************
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:

    The number of elements initialized in nums1 and nums2 are m and n respectively.
    You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.

Example:

    Input:
    nums1 = [1,2,3,0,0,0], m = 3
    nums2 = [2,5,6],       n = 3

    Output: [1,2,2,3,5,6]
***************************************************************/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, pos = m + n - 1;
        while(i >= 0 && j >= 0) {
            nums1[pos--] = (nums1[i] >= nums2[j]) ? nums1[i--] : nums2[j--];
        }
        if(j >= 0) {
            copy(nums2.begin(), nums2.begin() + j + 1, nums1.begin());
        }
    }
};

string join(const vector<int>& v, string c) {
    string s;
    for (vector<int>::const_iterator p = v.begin();
            p != v.end(); ++p) {
        s += to_string(*p);
        if (p != v.end() - 1)
            s += c;
    }
    return "[" + s + "]";
}

int main(void) {
    Solution s = Solution();
    vector<int> nums1 {1,2,3,0,0,0};
    vector<int> nums2 {2,5,6};
    int m = 3, n = 3;
    cout << "nums1 = [1,2,3,0,0,0], m = 3" << endl; 
    cout << "nums2 = [2,5,6],       n = 3" << endl;
    s.merge(nums1, m, nums2, n);
    cout << join(nums1, ",") << endl;

    nums1 = {-1,0,0,0,3,0,0,0,0,0,0};
    m = 5;
    nums2 = {-1,-1,0,0,1,2};
    n = 6;
    cout << "nums1 = [-1,0,0,0,3,0,0,0,0,0,0], m = 5" << endl; 
    cout << "nums2 = [-1,-1,0,0,1,2],          n = 6" << endl;
    s.merge(nums1, m, nums2, n);
    cout << join(nums1, ",") << endl;

    nums1 = {4,5,6,0,0,0};
    m = 3;
    nums2 = {1,2,3};
    n = 3;
    cout << "nums1 = [-1,0,0,0,3,0,0,0,0,0,0], m = 5" << endl; 
    cout << "nums2 = [-1,-1,0,0,1,2],          n = 6" << endl;
    s.merge(nums1, m, nums2, n);
    cout << join(nums1, ",") << endl;
    return 0;
}

