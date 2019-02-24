/*
  题目：
  给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素最多出现两次，返回移除后数组的新长度。
  不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
  
  做法：判断是否有连续的三个相等的数。
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len=nums.size();
        if(len<=2){//元素个数为0,1,2时，不会出现重复三次的情况。
            return len;
        }
               
        for(int i=0; i<=len-3; i++){
            if(nums[i]==nums[i+1]){        
                if(nums[i+1]==nums[i+2]){
                    nums.erase(nums.begin()+i+2);
                    i--;
                    len--;
                }
            }
        }        
        
        return len;
    }
};
