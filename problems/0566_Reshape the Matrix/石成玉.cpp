class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if(nums.size() < 1 || r * c != nums.size() * nums[0].size())
            return nums;
        vector<int> row(c, 0);
        vector<vector<int>> result(r, row);
        int x = 0, y = 0;
        for(int i=0; i<nums.size(); ++i)
            for(int j=0; j<nums[0].size(); ++j) {
                result[x][y++] = nums[i][j];
                if(y == c) {
                    y = 0;
                    ++x;
                }
            }
        
        return result;
    }
};
