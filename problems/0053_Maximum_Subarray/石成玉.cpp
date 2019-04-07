class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() < 1)
            return 0;
        int max_result = nums[0];
        int sub_sum = nums[0];
        for(int i=1; i<nums.size(); ++i) {
            if(sub_sum < 0)
                sub_sum = nums[i];
            else
                sub_sum += nums[i];
            if(sub_sum > max_result)
                max_result = sub_sum;
        }
        
        return max_result;
    }
};
