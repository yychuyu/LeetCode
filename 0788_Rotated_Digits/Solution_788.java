package leetcode_788;

public class Solution {
    public int rotatedDigits(int N) {
        int count = 0;
        for (int i = 1; i <= N; i ++) {
            if (isValid(i)) count ++;
        }
        return count;
    }

    public boolean isValid(int N) {
        boolean validNumber = false;
        while (N > 0) {
            if (N % 10 == 2||N % 10 == 5||N % 10 == 6||N % 10 == 9) validNumber = true;
            if (N % 10 == 3||N % 10 == 4||N % 10 == 7) return false;
            N /= 10;
        }
        return validNumber;
    }
}
