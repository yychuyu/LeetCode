/*
  题目：
  假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
  每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
  
  参考：
  https://blog.csdn.net/haimianxiaodao/article/details/52608536?utm_source=blogxgwz6
*/
class Solution {
public:
    int climbStairs(int n) {          
        int n_1 = 1;
        int n_2 = 0;
        
        int tmp;
        for(int i=1; i<=n; i++){       
            tmp = n_1+n_2;
            n_2 = n_1;
            n_1 = tmp;    
        }
    
        return tmp;
    }
};
