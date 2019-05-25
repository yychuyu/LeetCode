class Solution {
public:
	vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
		int row = nums.size();
		int column = nums[0].size();
		vector<vector<int>> R(r, vector<int>(c, 0));
		if(row * column != r*c)
			return nums;
		for(int i = 0; i < row; i++)
			for(int j = 0; j < column; j++)
			{
				int n = i * column + j;
				R[n/c][n%c] = nums[i][j];
			}
			return R;
	}
};