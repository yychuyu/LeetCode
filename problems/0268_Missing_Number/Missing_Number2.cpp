//20ms
/*
  题目：
  给定一个包含 0, 1, 2, ..., n 中 n 个数的序列，找出 0 .. n 中没有出现在序列中的那个数。
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int miss=nums.size();        
        for(int i=0; i<nums.size(); i++){
            miss = miss + (i-nums[i]);
        }
        return miss;
    }
};
