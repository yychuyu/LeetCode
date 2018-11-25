class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0;
        for(int i = 0;i < nums.size() - count;i++){
            if(nums[i] == val){
                count++;                            //记录移除元素个数
                nums[i] = nums[nums.size() - count];  //最后一个元素替换当前位置的元素
                i--;                                //移除一个元素，长度减1;
            }
        }
        return nums.size() - count;
    }
};
