class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> result(nums.size());
        result[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            if(result[i-1]>0)
                result[i]=nums[i]+result[i-1];
            else
                result[i]=nums[i];
        }
        return *max_element(result.begin(),result.end());//max_element返回的是迭代器，需要取值操作以匹配返回类型
    }
};
