
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        size_t length = nums.size();
        vector<int> arr;
        if(length > 1)
        {
            for(size_t i=0 ; i < length ; i++)
                for(size_t j=i+1;j<length;j++)
                {
                   if((nums[i]+ nums[j]) == target)
                     {
                         arr.push_back(i);
                         arr.push_back(j);
                         return arr;
                     }
                }
        }
        arr.clear();
        return arr;
        
    }
};
