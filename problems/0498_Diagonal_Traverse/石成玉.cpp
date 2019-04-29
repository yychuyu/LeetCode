class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int M = matrix.size() - 1;
        if(M < 0)
            return result;
        int N = matrix[0].size() - 1;
        bool is_up = true;
        int i = 0;
        int j = 0;
        
        while(i != M || j != N) {
            result.push_back(matrix[i][j]);
            if(is_up) {
                if(i == 0) {
                    if(j == N)
                        ++i;
                    else
                        ++j;
                    is_up = false;
                }
                else if(j == N) {
                    ++i;
                    is_up = false;
                }
                else {
                    --i;
                    ++j;
                }
            }
            else {
                if(i == M) {
                    ++j;
                    is_up = true;
                }
                else if(j == 0) {
                    ++i;
                    is_up = true;
                }
                else {
                    ++i;
                    --j;
                }
            }
        }
        result.push_back(matrix[M][N]);
        
        return result;
    }
};
