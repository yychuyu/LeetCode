class Solution {
public:
    int search(vector<int>& nums, int target) {
        int length  = nums.size();
        int low = 0;
        int high = length - 1;
        
        while(low<=high){
            int mid = low + ((high - low)>>1);
             if(nums[low] == target){
                    return low;
                }
                if(nums[high] == target){
                    return high;
                }
            if(nums[mid] < target){
               
                if(nums[low] < target && nums[low] > nums[mid]){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
                
            }
            else if(nums[mid]>target){
                if(nums[low]>target && nums[low] < nums[mid]){
                    low = mid + 1;
                }
                else{
                    high = mid -1;
                }
            }
            else{
                return mid;
            }
        }
        return -1;
    }
};