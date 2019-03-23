//url: https://leetcode.com/problems/reshape-the-matrix/submissions/
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int total = nums.size()*nums[0].size();
        if (total != r*c){
            return nums;
        }
        vector<int> temp;
        for (int i=0; i<nums.size(); i++){
            for (int j=0; j<nums[i].size(); j++){
                temp.push_back(nums[i][j]);
                //cout<<nums[i][j]<<endl;
            }
        }
        int k=0;
        vector<vector<int>> ret;
        for (int i=1; i<=r; i++){
            vector<int> ret_temp;
            for (int j=1; j<=c; j++){
                ret_temp.push_back(temp[k++]);
            }
            ret.push_back(ret_temp);
        }
        return ret;
    }
};
