/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     ：Torres Ng
*   Create Time ：2018/10/08
*
***************************************************************/
/**************************************************************
题目：
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
释义：
给定整型数组，返回两个数的下标，使得这两个数相加得到特定的值。
假设每个给定的数组只能找到一组满足条件的结果，同时，不能使用同一个数两次。

分析：
题大意为，在一组数组中，找到两个数，使得这两个数的和等于特定值，并返回下标。可以从第一个数开始，循环与后面的每一个相加，与结果比较，比较成功则返回。
例如，输入[1,7,11,15],目标值26，那么循环计算1+7,1+11,1+15，7+11,7+15......，直到得到目标值。
***************************************************************/

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

unique_ptr<pair<int, int>> twosum(vector<int> v, int target) {
    size_t length = v.size();
    if(length < 2) {
        return unique_ptr<pair<int,int>>(nullptr);
    }
    for(size_t i = 0; i < length - 1; i++) {
        for(size_t j = i + 1; j < v.size(); j++) {
            if((v[i] + v[j]) == target) {
                return unique_ptr<pair<int,int>>(new pair<int,int>(i, j));
            }
        }
    }
    return unique_ptr<pair<int,int>>(nullptr);
}

int main(void) {
    vector<int> v = {2,7,11,15};
    unique_ptr<pair<int, int>> result = twosum(v, 9);
    if(result == nullptr) {
        cout << "not fount !" << endl;
    } else {
        cout << "index: " << result->first << "," << result->second << endl;
    }
    return 0;
}
