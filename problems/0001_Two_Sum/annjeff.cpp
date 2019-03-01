class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       vector<int> ret;
        bool flag = false;
       for(int i = 0;i<nums.size()-1;i++)
       {
           if(flag)break;
           for(int j = i+1;j<nums.size();j++)
           {
               if(target == nums[i]+nums[j])
               {
                    ret.push_back(i);
                    ret.push_back(j);
                   flag = true;
                   break;
               }
                
           }
       }
    return ret;

    }
};