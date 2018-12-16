/*
  题目：
  给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
  你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len=nums.size();
        for(int i=0; i<=len-2; i++){
            for(int j=i+1; j<=len-1; j++){
                if(nums[i]+nums[j] == target){
                    return vector<int>{i,j};
                }
            }
        }
    }
};
