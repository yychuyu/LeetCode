/*
思路： 1. 从集合[1,2,3]中，一个一个添加数字；最开始是[[]];添加1，像每个集合添加1，变成[[1]],然后合并，变成[[],[1]]; 添加2变成[[2],[1,2],然后合并变成[[],[1],[2],[1,2]]；...
可参考：http://www.cnblogs.com/grandyang/p/4309345.html

time: O(2^n),和子集的个数有关
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> res;
        vector<int> tmp;
        res.push_back(tmp);
        
        for(int i = 0; i < nums.size(); i++){         // 逐个添加数字
            int size = res.size();
            for(int j = 0; j < size; j++){    //把新元素添加到生成的数组中
                tmp = res[j];
                tmp.push_back(nums[i]);
                res.push_back(tmp);         //合并到res中
            }
        }
        
        return res;
    }
};
