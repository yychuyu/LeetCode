/*
  题目：
  统计所有小于非负整数 n 的质数的数量。

  示例:
  输入: 10
  输出: 4
  解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
*/
class Solution {
public:
    int countPrimes(int n) {
        if(n<2)
            return 0;
      
        int mark[n]={0};
        for(int i=2;i*i<n;i++){
            if(mark[i]==0){
                for(int j=i;i*j<n;j++){
                    mark[i*j]=1;
                }
            }
        }
        
        int cnt=0;
        for(int i=2;i<n;i++){
            if(mark[i]==0)
                cnt++;
        }
        
        return cnt;
    }
};
