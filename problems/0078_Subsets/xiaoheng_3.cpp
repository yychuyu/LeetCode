class Solution {
public:
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<int> temp;   //暂存out中的元素
        vector<vector<int>> out;    //输出的二维数组
        out.push_back(temp);    //进 '[]' 空数组
        
        for(int i = 0;i < nums.size();i++){     //迭代nums中的元素
            
            int len = out.size();   //暂存out长度，因为下面会变
            for(int j = 0; j < len;j++){    //迭代out
                
                temp = out[j];
                temp.push_back(nums[i]);
                out.push_back(temp);
                
            }
        }
        
        return out;
    }   
};
