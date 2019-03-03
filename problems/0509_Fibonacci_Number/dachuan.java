class Solution {
    public int fib(int N) {
        //方法一：动态规划（速度更快）
        if (N == 0) {
            return 0;
        }else if(N == 1){
            return 1;
        }else {
            int[] nums = new int[N + 1];
            nums[0] = 0;
            nums[1] = 1;
            for (int i = 2; i < N + 1; i++) {
                nums[i] = nums[i - 1] + nums[i - 2];
            }
            return nums[N];
        }

        //方法二：递归
//        if (N == 0) {
//            return 0;
//        }else if(N == 1){
//            return 1;
//        }else{
//            return fib(N - 1) + fib(N - 2);
//        }
    }
}