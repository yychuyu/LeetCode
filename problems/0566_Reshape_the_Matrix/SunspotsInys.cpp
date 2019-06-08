/**
 * 思路很朴素。
 * 首先判断能不能行。
 * 能行，就申请一个r行的数组，挨个填进去就行了
 * 很开心，我的提交执行用时已经战胜 95.43 % 的 cpp 提交记录
 */

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if (nums.size()*nums[0].size() != r*c) {
            return nums;
        }
        vector<vector<int> > num(r);
        int rl=0, cl=0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums[0].size(); ++j) {
                if (cl < c) {
                    num[rl].push_back(nums[i][j]);
                    cl++;
                } else {
                    cl = 0;rl++;
                    num[rl].push_back(nums[i][j]);
                    cl++;
                }
            }
        }

        return num;
    }
};
