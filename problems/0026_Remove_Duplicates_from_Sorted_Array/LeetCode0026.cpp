/*
移除数组中多余元素，输出
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(); 
        if(n == 0)
            return 0;
        int num = 0;
        for(int i = 0;i < n-1;i++)
        {
            if(nums[i] != nums[i+1])
            {
                nums[++num] = nums[i+1];//修改原数组
            }
        }
        return num+1;//返回新数组的长度
    }
};

int main()
{
    vector<int> nums{1,2,2,3,3,4,4,5,6};
    Solution method;
    int num = method.removeDuplicates(nums);
    cout << "Length:"<<num<<endl;
    for (int i = 0; i < num;i++)
    cout << nums[i] <<" ";
    cout << endl;
    return 0;
}
