class Solution {
    public int maxProfit(int[] prices) {
        int cur = 0, maxi = 0;
        for (int i=1; i<prices.length; i++) {
            cur += prices[i] - prices[i-1];
            if (cur < 0) cur = 0;
            maxi = cur > maxi ? cur : maxi;
        }
        return maxi;
    }
}
