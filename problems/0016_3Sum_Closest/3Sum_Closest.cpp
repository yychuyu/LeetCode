/*
  题目：
  给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。  返回这三个数的和。
  假定每组输入只存在唯一答案。

  示例：
  给定数组 nums = [-1，2，1，-4], 和 target = 1.
  与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
  
  参考：
  https://www.cnblogs.com/ariel-dreamland/p/9128158.html
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {       
        int len = nums.size();
        if(len<3){
            return 0;
        }    
        if(len==3){             
            return nums[0]+nums[1]+nums[2];
        }
        
        sort(nums.begin(),nums.end());
        //排序后，左边小右边大。如果三个数加起来发现小于target，left向右移一个（多加点）。
        
        int min_sum=INT_MAX, min_dis=INT_MAX;
        for(int i=0; i<len-2; i++){
            int left=i+1, right=len-1;
            
            while(left<right){
                int sum = nums[i]+nums[left]+nums[right];
                int dis = abs(sum-target);
                if(dis<min_dis){
                    min_sum=sum;
                    min_dis=dis;
                }
                if(sum<target){
                    left++;
                }else{
                    right--;
                }
            }  
            
        }
        
        return min_sum;        
    }
};
