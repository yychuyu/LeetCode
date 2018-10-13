/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     ：Torres Ng
*   Create Time ：2018/10/08
*
***************************************************************/
/**************************************************************
题目：
给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。

Example 1:
给定数组 nums = [1,1,2], 

函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。 

你不需要考虑数组中超出新长度后面的元素。

Example 2:
给定 nums = [0,0,1,1,1,2,2,3,3,4],

函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。

你不需要考虑数组中超出新长度后面的元素。
***************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int> &nums) {
    if(nums.empty()) {
        return 0;
    }
    vector<int>::iterator iter1 = nums.begin();
    vector<int>::iterator iter2 = iter1 + 1;
    size_t count = nums.size();

    while(iter2 != nums.end()) {
        if(*iter1 == *iter2) {
            --count;
        } else {
            if((iter2 - iter1) == 1) {
                ++iter1;
            } else {
                ++iter1;
                *iter1 = *iter2;
            }
        }
        ++iter2;
    }
    return count;
}

int main(void) {
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    size_t len = removeDuplicates(nums);
    cout << "len: " << len << endl;
    for(int i = 0; i < len; i++) {
        cout << nums[i] << ' ';
    }
    cout << endl;

    return 0;
}
