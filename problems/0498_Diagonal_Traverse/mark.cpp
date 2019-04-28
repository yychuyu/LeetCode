/*
参考：https://www.cnblogs.com/grandyang/p/6414461.html
*/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        
        if (matrix.empty() || matrix[0].empty() )
            return { };
        
        int m = matrix.size();
        int n = matrix[0].size();
        int r = 0, c = 0, k = 0;
        
        vector<int> res(m*n);
        vector<vector<int>> dir{{-1,1}, {1,-1}};  // 用于改变遍历方向
        
        for(int i = 0; i < m*n; i++){
            res[i] = matrix[r][c];
            r += dir[k][0];
            c += dir[k][1];
            
            if ( r >= m){   // 右上角情况
                r = m -1;
                c += 2;
                k = 1 - k;
            }
            
            if ( c >= n ){   // 左下角情况
                c = n - 1;
                r += 2;
                k = 1 - k;
            }
            
            if (c < 0){    // 改变方向
                c = 0;
                k = 1 - k;
            }
            
            if ( r < 0){
                r = 0;
                k = 1 - k;
            }
        }
        
        return res;
        
    }
};
