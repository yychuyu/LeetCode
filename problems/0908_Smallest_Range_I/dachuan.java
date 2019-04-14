class Solution {
    public int smallestRangeI(int[] A, int K) {
        Arrays.sort(A);
        int min = A[0];
        int max = A[A.length - 1];
        if(min == max){
            return 0;
        }else if (max - min > K * 2) {
            return max - min - K * 2;
        }else{
            return 0;
        }
    }
}
//这道题的解答倒是很简答，就是题目看了好几遍，完全不知道出题的想表达什么，在理解题目的意思上花了大量的时间