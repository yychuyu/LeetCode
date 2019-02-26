/*
  题目：
  给定一个整数数组，判断是否存在重复元素。
  如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。
  
  做法：可以先排序，这样相同的元素会相邻。
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1){
            return false;
        }
        
        sort(nums.begin(), nums.end());
        for(int i=0; i<=len-2; i++){
            if( nums[i] == nums[i+1] ){
                return true;
            }
        }
        
        return false;
    }
};
