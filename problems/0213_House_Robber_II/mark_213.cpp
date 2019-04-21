
// 动态规划，和Robber1类似，多了收尾的限制，可以分两次去掉首尾元素，然后各求一下最大值，即为所求。
// 维护一个动态数组，dp[i]记录在当前位置最大和；转移方程：dp[i] = max(num[i] + dp[i - 2], dp[i - 1])
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        return max(rob(nums, 0, nums.size()-1), rob(nums, 1, nums.size()));   // 去掉第一个和去掉最后一个的较大值
    }
    
    int rob(vector<int>& nums, int first,int end){
        if(end - first <= 1) return nums[first];           //当子数组只有一个或者两个元素，直接返回
        vector<int> dp(end);
        dp[first] = nums[first];
        dp[first+1] = max(nums[first], nums[first+1]);      
        for(int i = 2; i < end; ++i){
            dp[i] = max(nums[i] + dp[i-2], dp[i-1]);      // 动态规划找到当前位置最大值
        }
        
        return dp[end-1];
    }
};
