class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (1 == nums.size()){
            return nums[0];
        }
        int result = nums[0];
        for (int i=1;i<nums.size();i++){
            result ^= nums[i];
        }
        return result;
    }
};