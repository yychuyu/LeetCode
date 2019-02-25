/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     ：Torres Ng
*   Create Time ：2018/12/1
*
***************************************************************/
/**************************************************************
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]

Note:

    1. You must do this in-place without making a copy of the array.
    2. Minimize the total number of operations.
***************************************************************/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int zero_num = 0;
        const size_t size = nums.size();
        for(int idx = 0, i = 0; i < size; i++) {
            if(nums[i] != 0) {
                nums[idx] = nums[i];
                idx++;
            } else {
                zero_num++;
            }
        }
        while(zero_num) {
            nums[size - zero_num] = 0;
            zero_num--;
        }
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
    vector<int> vec {0,1,0,3,12};
    cout << "Input: [0,1,0,3,12]" << endl;
	cout << "Output: ";
    s.moveZeroes(vec);
    cout << join(vec, ",") << endl;
    

    return 0;
}
