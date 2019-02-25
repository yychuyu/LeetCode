/**
 * 	the website about the detail for the problem:
 *	https://leetcode.com/problems/house-robber/description/
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;

        // 递归求解 （ Time Limit Exceeded）
		/***
        int sz = static_cast<int>(nums.size());
        return rec_opt(nums, sz - 1);
		***/

        // 非递归求解（right！！！）
        int sz = static_cast<int>(nums.size());
        return dp_opt(nums, sz);
    }

    int rec_opt(vector<int> &arr, int n) {
        if (n == 0)
            return arr[0];
        else if (n == 1)
            return max(arr[0], arr[1]);
        else
        {
            int num1 = arr[n] + rec_opt(arr, n - 2);
            int num2 = rec_opt(arr, n - 1);
            return max(num1, num2);
        }
    }

    int dp_opt(vector<int> &arr, int n) {
        vector<int> opt(n);
        opt[0] = arr[0];
        opt[1] = max(arr[0], arr[1]);

        for (int i = 2; i < n; ++i) {
            int num1 = opt[i-2] + arr[i];
            int num2 = opt[i-1];
            opt[i] = max(num1, num2);
        }

        return opt[n-1];
    }

};

void assignVal(vector<int>& nums, int n)
{
    int num;

    for (int i = 0; i < n; ++i)
    {
        cin >> num;
        nums.push_back(num);
    }
}

/***
void print(vector<int> &nums)
{
    for (auto e: nums)
    {
        cout << e << " ";
    }
    cout << endl;
}
***/

int main(int argc, char const *argv[])
{
    vector<int> nums;
    int n;

    Solution a;

    cin >> n;			// 数组元素的个数
    {
        assignVal(nums, n);
        print(nums);
        cout << "max:" << a.rob(nums) << endl;
    }

    return 0;
}
