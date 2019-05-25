class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len_nums = nums.size();
        int end_nums = len_nums - 1;
        int i = 0;
        while(i <= end_nums)
        {
            if(nums[i]==val){  
                int temp = nums[i];
                nums[i] = nums[end_nums];
                nums[end_nums] = temp; 
                end_nums = end_nums - 1;  
            }
            else 
            {
                i = i + 1;
            }
               
        }
       return end_nums + 1;
    }
};