// 第27题 移除重复的元素
// 这里判断数组的i号元素是不是要删除的，是的话， 计数，
// 然后将其重新赋值给这个数组咯！

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt =0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == val)
                cnt++;
            else
                nums[i - cnt] = nums[i];
        }
        return nums.size()-cnt;
    }
};
