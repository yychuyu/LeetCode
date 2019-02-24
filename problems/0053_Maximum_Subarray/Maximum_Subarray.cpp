//仅为解法之一
/*
  题目：
  给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

  示例:
  输入: [-2,1,-3,4,-1,2,1,-5,4],
  输出: 6
  解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。

  参考：
  https://www.cnblogs.com/jimmycheng/p/7204034.html
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        
        int sum=0, max=INT_MIN;
        int len=nums.size();
        for(int i=0;i<len;i++){
            sum=std::max(nums[i],sum+nums[i]);
            max=std::max(max,sum);
        }
        
        return max;
    }
};
