
//第26题。
//用的快慢指针的方法来完成的。


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int pre = 0, cur = 0, n = nums.size();
        while (cur < n) {
            if (nums[pre] == nums[cur]) ++cur;
            else nums[++pre] = nums[cur++];
        }
	}
    return pre + 1;    
};
