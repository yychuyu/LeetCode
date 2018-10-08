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
    if(nums.size() < 0) {
        return 0;
    }
    int pos = 1;
    int value = nums[0];
    size_t len = 1;
    for(int i = 1; i < nums.size(); i++) {
        if(value != nums[i]) {
            nums[pos] = nums[i];
            pos++;
            value = nums[i];
            len++;
        }
    }
    nums.resize(len);
    return len;
}

int main(void) {
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    size_t len = removeDuplicates(nums);
    cout << "len: " << len << endl;
    for(int v : nums) {
        cout << v << ' ';
    }
    cout << endl;

    return 0;
}
