/*
question URL:https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
*/
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        int max = nums.size();
        vector<int> vec;
        max++;
        bool isAppeared[max] = {false};
        
        for (auto it = nums.begin(); it!= nums.end(); it++){
            isAppeared[*it] = true;
        }
        for (int i=1; i<max; i++){
            if (isAppeared[i] == false)
                vec.push_back(i);
        }
        
        return vec;
        
    }
};
