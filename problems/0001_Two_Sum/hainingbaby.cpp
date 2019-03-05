class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    	// 时间复杂度O(n^2)
    	for(int i = 0; i<nums.size(); ++i){
    		for(int j = i+1; j < nums.size(); ++j){
    			int tar = nums[i] + nums[j];
    			if(tar == target){
    				return {i,j};
    			}
    		}
    	}
    	return {};
    }
};