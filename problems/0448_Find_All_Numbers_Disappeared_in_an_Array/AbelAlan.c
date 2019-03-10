class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int num= nums.size();
        vector<int> result;
        for(int i=0; i < num;i++)
        {
            int m = abs(nums[i]) - 1;
            nums[m] = nums[m] > 0 ? -nums[m]:nums[m];
        }
        for(int i = 0; i < num; i++)//寻找索引大于0
        {
            if(nums[i] > 0)
                result.push_back(i+1);
                //result.Add(i+1);
        }
        return result;
        
    }
};


