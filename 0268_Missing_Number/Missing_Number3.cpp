//20ms，用的方法：异或运算。
/*
  题目：
  给定一个包含 0, 1, 2, ..., n 中 n 个数的序列，找出 0 .. n 中没有出现在序列中的那个数。

  参考：
  https://www.cnblogs.com/king-3/archive/2018/05/31/9117558.html
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len=nums.size();
        int rst=0;
    
        for(int i=0;i<len;i++){
            rst=rst^nums[i]^i;
        }
        
        return rst^len;
    }
};
