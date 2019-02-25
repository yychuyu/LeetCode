/*
  给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
  说明：
  你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        int len=nums.size();
        for(int i=0;i<len;i=i+2){
            if( nums[i] != nums[i+1] ){
                return nums[i];
            }
        }
        
        return nums[len-1];        
    }
};
