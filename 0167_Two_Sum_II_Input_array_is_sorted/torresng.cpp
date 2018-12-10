/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     Torres Ng
*   Create Time 2018/12/10
*
***************************************************************/
/**************************************************************
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.

Note:

    Your returned answers (both index1 and index2) are not zero-based.
    You may assume that each input would have exactly one solution and you may not use the same element twice.

Example:

    Input: numbers = [2,7,11,15], target = 9
    Output: [1,2]
    Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
***************************************************************/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> umap;
        int sub;
        for(int i = 0; i < numbers.size(); i++) {
            sub = target - numbers[i];
            unordered_map<int, int>::iterator iter = umap.find(sub);
            if(umap.find(sub) != umap.end()) {
                return {iter->second+1, i+1};
            }
            umap[numbers[i]] = i;
        }
        return {};
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

    vector<int> numbers {2,7,11,15};
    int target = 9;
	cout << "Input: numbers = [2,7,11,15], target = 9" << endl << "Output: ";
    vector<int> res = s.twoSum(numbers, target);
    cout << join(res, ",") << endl;
	return 0;
}

