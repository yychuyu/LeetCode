/*
    Runtime: 132 ms, faster than 36.84% of C++ online submissions for Two Sum.
    Memory Usage: 9.3 MB, less than 84.28% of C++ online submissions for Two Sum.
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++)
            for(int j = i + 1; j < nums.size(); j++)
                if (nums[i] + nums[j] == target)
                    return vector{i,j};
        
        return vector{0,0};     
    }
};