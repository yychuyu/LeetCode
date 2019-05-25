/*
1. 这个递归公式不太明白，卡特兰数
2. 参考：http://www.cnblogs.com/grandyang/p/4299608.html
*/

class Solution {
public:
    int numTrees(int n) {
        vector<int> sum(n+1,0);
        sum[0] = 1;
        sum[1] = 1;
        
        for(int i = 2; i < n+1; i++){
            for(int j = 0; j < i; j++){
                sum[i] += sum[j] * sum[i-j-1];
            }
        }
        
        return sum[n];
    }
};
