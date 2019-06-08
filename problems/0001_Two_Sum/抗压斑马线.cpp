
/*
01. Two Sum
    Given an array of integers, return indices of the two numbers such that they add up to a specific target.
    You may assume that each input would have exactly one solution, and you may not use the same element twice.
    Example:
    Given nums = [2, 7, 11, 15], target = 9,

    Because nums[0] + nums[1] = 2 + 7 = 9,
    return [0, 1].
-----------------------------------------------------------------------------------
|    Runtime: 132 ms, faster than 36.84% of C++ online submissions for Two Sum.   |
|    Memory Usage: 9.3 MB, less than 84.28% of C++ online submissions for Two Sum.|
-----------------------------------------------------------------------------------
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


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        recursiveAchieve(ans, "", 0, 0, n);
        return ans;
    }
    
    void recursiveAchieve(vector<string> str, String border, int strat, int end, int count)
    {
        if  (border.length() == count * 2)
        {
            str.insert(border);
            return;
        }
        
        if (start < count)
        {
            recursiveAchieve(str, border, start + 1, end, count);
        }
        
        if (end < count)
        {
            recursiveAchieve(str, border, start, end + 1, count);
        }
    }
};
