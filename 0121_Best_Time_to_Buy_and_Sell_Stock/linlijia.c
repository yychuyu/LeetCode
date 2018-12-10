class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        int maxProfit = 0;

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int t = prices[j] - prices[i];
                if (t > 0 && t > maxProfit) 
                    maxProfit = t;
                
            }
        }
               
        return maxProfit;
    }
};