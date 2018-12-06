class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int len = nums.size();
        if(len < 1)return 0;
        int i = 0,j=1;
        while(i < len && j < len)
        {
            if(nums[i]==nums[j])
            {
                j++;
            }
            else
            {
                nums[++i] = nums[j];
            }
        }
        return i+1;
    }
};
