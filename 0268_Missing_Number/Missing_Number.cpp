//28ms, 应该会有更好的方法。用到了排序，不是很合题意。
/*
  题目：
  给定一个包含 0, 1, 2, ..., n 中 n 个数的序列，找出 0 .. n 中没有出现在序列中的那个数。
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        if(nums.size()==1){
            return nums[0] ? 0 : 1;
        }

        sort(nums.begin(),nums.end());
        if(nums[0]!=0){
            return 0;
        }
     
        int len=nums.size();
        for(int i=0;i<len-1;i++){
            if(nums[i]+1 != nums[i+1]){
                return nums[i]+1;
            }
        }
        return nums[len-1]+1;
    }
};
