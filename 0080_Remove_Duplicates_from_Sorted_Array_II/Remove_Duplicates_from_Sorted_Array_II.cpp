/*
  题目：
  给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素最多出现两次，返回移除后数组的新长度。
  不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
  
  做法：逐步生成新数组。
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
                
        int new_idx=1;
        
        int val=nums[0], cnt=1;
        for(int idx=1; idx<nums.size(); idx++){
            if(val!=nums[idx]){//新出现的元素
                val=nums[idx];
                cnt=1;
            }else if(cnt==1){//第二次出现
                cnt=2;
            }else{//第三次出现
                continue;
            }
            
            nums[new_idx]=nums[idx];
            new_idx++;
        }
        
        return new_idx;        
    }
};
