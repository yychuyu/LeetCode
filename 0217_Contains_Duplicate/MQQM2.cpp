/*
  题目：
  给定一个整数数组，判断是否存在重复元素。
  如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。
  
  做法：用一个vector存储当前只出现一次的元素。
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1){
            return false;
        }
        
        vector<int> vec;
        for(int i=0; i<=len-1; i++){
            if( find(vec.begin(), vec.end(), nums[i]) != vec.end() ){
                return true;
            }else{
                vec.push_back(nums[i]);
            }      
        }
        
        return false;
    }
};
