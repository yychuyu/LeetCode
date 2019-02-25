/*
  题目：
  给定一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，返回移除后数组的新长度。
  不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
  元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
  
  做法：前后“指针”。
*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len=nums.size();        
        int front=0;
        int rear=len-1;
        
        while(front<=rear){
            while(front<=rear && nums[front]!=val){
                front++;
            }
            while(front<=rear && nums[rear]==val){
                rear--;
                len--;//从后往前遍历时，发现欲删除的元素。
            }        
            if(front<rear){
                nums[front]=nums[rear];
                nums[rear]=val;
            }            
        }
    
        return len;
    }
};
