/*
  题目：
  给定一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，返回移除后数组的新长度。
  不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
  元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
  
  参考：
  https://blog.csdn.net/feliciafay/article/details/17703449
  
  做法：逐步生成新数组(遇到欲删除的元素时，不作复制)。
*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int new_idx=0;
        for(int idx=0; idx<nums.size(); idx++){
            if(nums[idx]!=val){
                nums[new_idx]=nums[idx];
                new_idx++;
            }
        }
        
        return new_idx;
    }
};
