/**
* LeetCode The 26th problem :remove-duplicates-from-sorted-array
* Auth:Barlowwang
* Date:2018-10-08
**/ 
#include <vector>
#include <iostream>
using namespace std;
/*  C version
int removeDuplicates(int* nums, int numsSize) {
     if (numsSize == 0)
        return 0;
    int current = 0;
    for (int i = 0; i < numsSize; ++i)
    {
        if (nums[i] != nums[current])
        {
            nums[++current] = nums[i];
        }
    }
    return current + 1;
    
}
*/
int removeDuplicates(vector<int>& nums)
{
    if (nums.size() == 0)
        return 0;
    int current = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != nums[current])
        {
            nums[++current] = nums[i];
        }
    }
    return current + 1;
}


int removeDuplicates(vector<int> &nums)
{
    if (nums.size() == 0)
        return 0;
    int current = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != nums[current])
        {
            nums[++current] = nums[i];
        }
    }
    return current + 1;
}
int main()
{
    vector<int> num;
    int t, temp;
    cin >> t;
    while (t != 0)
    {
        cin >> temp;
        num.push_back(temp);
        t--;
    }
    t = removeDuplicates(num);
    for (int i = 0; i < t; i++)
    {
        cout << num[i] << "  ";
    }
    cout << endl;
    system("pause");
}