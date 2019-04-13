// 写的比较菜，只会用传统方法，看 discuss 那些大佬都用的 hash table， 要去学习一下数据结构了
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> index;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            int j = i + 1;
            
            for (int k = j; k < nums.size(); k++)
            {
                if (nums[i] + nums[k] == target){
                    index.push_back(i);
                    index.push_back(k);
                }
            }
        }
        return index;
    }
};
