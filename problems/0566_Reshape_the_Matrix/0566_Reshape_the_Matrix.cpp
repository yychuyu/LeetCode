class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if (r * c != nums.size() * nums[0].size()) return nums;
        int ro = 0, co = 0;
        vector<vector<int>> res;
        vector<int> ans;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (co >= nums[0].size()) { ro++; co = 0; }
                ans.push_back(nums[ro][co++]);
            }
            res.push_back(ans);
            ans.clear();
        }
        return res;
    }
};
