/*
  题目：
  给定长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。
  
  做法：用额外的两个数组。
  一个数组其i位存放：nums数组中第i位元素之前的乘积；
  另一个数组其i位存放：nums数组中第i位元素之后的乘积。
  
  参考：
  https://blog.csdn.net/HeXiQuan123/article/details/80807956?utm_source=blogxgwz5
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> pre(len);
        vector<int> aft(len);
        vector<int> output(len);
        
        int pre_prod = 1;
        int aft_prod = 1;
        for(int i=1; i<=len-1; i++){
            pre_prod *= nums[i-1];
            pre[i] = pre_prod;
            
            aft_prod *= nums[len-i];
            aft[len-i-1] = aft_prod;
        }
        pre[0] = 1;
        aft[len-1] = 1;
        
        for(int i=0; i<len; i++){
            output[i] = pre[i] * aft[i];
        }
        
        return output;
    }
};
