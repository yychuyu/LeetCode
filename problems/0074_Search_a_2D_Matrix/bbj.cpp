class Solution {
public:
    // stl 不是太熟悉，要多看，不过这种答案都能超过100%的人2333
    // 直接用是 stl 模板里的指针肯定更快
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool flag = false;
        // vector<vector<int> >::iterator it;
        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[i].size(); j++){                
                if (matrix[i][j] == target){
                    flag = true;
                    return flag;
                }
            }
        }
        return flag;
    }
};
