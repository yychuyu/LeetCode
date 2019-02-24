/*
  题目：
  给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的连续子数组。如果不存在符合条件的连续子数组，返回 0。  
  
  示例: 
  输入: s = 7, nums = [2,3,1,2,4,3]
  输出: 2
  解释: 子数组 [4,3] 是该条件下的长度最小的连续子数组。
*/
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {        
        int len=nums.size();
        int minLen=len+1;
        
        int start=0, end=0;
        int sum=0;
        
        while(end<len){// sliding window
            sum += nums[end];   
            end++;
            while(sum>=s){
                minLen=minLen < end-start ? minLen : end-start ;
                sum -= nums[start];
                start++;
            }
        }
        
        return minLen==len+1 ? 0 : minLen;
    }
};
