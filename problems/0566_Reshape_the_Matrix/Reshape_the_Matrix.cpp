class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int row  = nums.size(), colum = nums[0].size();
        if (row  * colum != r * c) return nums;
        vector<vector<int>> res(r, vector<int>(c));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                int k = i * c + j;
                res[i][j] = nums[k / colum][k % colum];
            }
        }
        return res;
    }
};
