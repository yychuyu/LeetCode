//缺失的最小整数
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        if(n<=0)
        return 1;
        int num = 0;
        for(int i = 0; i < n; i++)
        {
            num = nums[i];
            while(num > 0 && num < n && nums[num - 1] != num)
            {
                swap(nums[i],nums[num-1]);
                num = nums[i];
            }
        }
        for(int i = 0; i < n; i++){
            if(i+1!=nums[i]){
                return i+1;
            }
        }
        return n+1;
    }
};


int main()
{
    Solution method;
    vector<int> nums = {6,4,3,7,1,9,8};
    cout << method.firstMissingPositive(nums);
    return 0;
}
