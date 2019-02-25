class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int unique = 1;
        int before = nums[0];
        int len = 1;
        for(int i=1;i<nums.size();i++){
            if(before !=nums[i]){
                nums[unique++] = nums[i];
                before = nums[i];
                len++;
            }
        }
        return len;
    }
};