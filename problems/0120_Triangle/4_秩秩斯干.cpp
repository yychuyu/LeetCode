class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 0) return 0;
        int row = triangle.size() - 2;
        for (; row >= 0; row--) {
            for (int col = 0; col < triangle[row].size(); col++) {
                triangle[row][col] += min(triangle[row + 1][col], triangle[row + 1][col + 1]);
            }
        }
        return triangle[0][0];
    }
};
