class Solution {
    public int maxProfit(int[] prices) {
        //是在最低的时候买么？不是，最低的时候可能是最后一天
        //遍历数组，找到max(prices[j]−prices[i])
        int maxprofit=0;
        for(int i=0;i<prices.length-1;i++){
            for(int j=i+1;j<prices.length;j++){
                int max=prices[j]-prices[i];
                if(max>maxprofit){
                    maxprofit=max;
                }
            }
        }
        return maxprofit;
    }
}