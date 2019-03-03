/*
  题目：
  假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
  每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
  
  做法：第n个台阶的走法 = 第n-1个台阶的走法 + 第n-2个台阶的走法。
  所以可以把问题“分解”，先求 第n-1个台阶的走法 和 第n-2个台阶的走法。
  为避免重复计算(求n需要先计算n-1和n-2，求n-1需要先计算n-2和n-3，这样n-2需要计算两次)，用一个数组把各个台阶的走法记录下来。
  
  参考：
  https://blog.csdn.net/qq_38595487/article/details/79686081
*/
class Solution {
    public int climbStairs(int n) {
        if(n == 1){
            return 1;
        }
        if(n == 2){
            return 2;
        } 
        
        int[] nums = new int[n+1];
        nums[1] = 1;
        nums[2] = 2;
        
        climb(nums,n);
        
        return nums[n];
    }
    
    public static void climb(int[] nums, int n){
        if(nums[n] != 0){//这个if把运行时间从4ms减少至2m(参考链接的代码没有这个if)
            return;
        }
        
        if(n-1 > 2 && nums[n-1] == 0){
            climb(nums, n-1);
        }
        if(n-2 > 2 && nums[n-2] == 0){
            climb(nums, n-2);
        }
        
        nums[n] = nums[n-1] + nums[n-2];
    }
}
