class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums[0] > target) return 0;
        if (nums[nums.size()-1] < target) return nums.size();
        
        int min=0;
        int max=nums.size()-1;
        int index=(min+max)/2;
        
        while(min != max){
            index = min + ((max-min)>>1); //防溢出
            if (target < nums[index]){
                max = index;
            }
            else if (target > nums[index]){
                min = index;
            }
            else{
                return index;
            }
            if (1 == max - min){
                return target==nums[min] ? min:max;
            }
            
        }
        return index;
    }
};