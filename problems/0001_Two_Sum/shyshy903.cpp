class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> vec;
        map<int,int> dic;
        for(int i=0;i<nums.size();++i){
            dic[nums[i]]=i;
        }
        for(int i=0;i<nums.size();++i){
            if(dic.count(target-nums[i])!=0 && dic[target-nums[i]] != i){
                vec.push_back(i);
                vec.push_back(dic[target-nums[i]]);
                break;
            }
        }
        return vec;
    }
};
This file is added by shy
This file is added by shyshy
