/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     ：Torres Ng
*   Create Time ：2018/11/30
*
***************************************************************/
/**************************************************************
Given two arrays, write a function to compute their intersection.

Example 1:

    Input: nums1 = [1,2,2,1], nums2 = [2,2]
    Output: [2]

Example 2:

    Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
    Output: [9,4]

Note:

    * Each element in the result must be unique.
    * The result can be in any order.
***************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        set<int> s;
        for(int v : nums1) {
            s.insert(v);
        }
        for(int v : nums2) {
            set<int>::iterator it = s.find(v);
            if(it != s.end()) {
                res.push_back(*it);
                s.erase(it);
            }
        }
        return res;
    }
};

template<class T>
string join(const vector<T>& v, string c) {
    string s;
    for (typename vector<T>::const_iterator p = v.begin();
            p != v.end(); ++p) {
        s += to_string(*p);
        if (p != v.end() - 1)
            s += c;
    }
    return "[" + s + "]";
}

int main(void) {
    Solution s = Solution();

    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};
    cout << "Input: nums1 = [1,2,2,1], nums2 = [2,2]" << endl;
    vector<int> res = s.intersection(nums1, nums2);
    cout << "Output: " << join(res, ",") << endl;

    nums1 = {4,9,5};
    nums2 = {9,4,9,8,4};
    cout << "Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]" << endl;
    res = s.intersection(nums1, nums2);
    cout << "Output: " << join(res, ",") << endl;

    return 0;
}

