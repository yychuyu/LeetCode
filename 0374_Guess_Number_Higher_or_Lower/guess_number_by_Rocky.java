/* The guess API is defined in the parent class GuessGame.
   @param num, your guess
   @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
      int guess(int num); */

public class Solution extends GuessGame {
    public int guessNumber(int n) {
        int low = 1, high = n; 
        int r = guess(low + (high - low) / 2);
        int tmp;
        
        while (r != 0) {
            tmp = low + (high - low) / 2;
            if (r == -1) {
                high = tmp - 1; 
            }
            else if (r == 1) {
                low = tmp + 1;
            }
            r = guess(low + (high - low) / 2);
        }
        
        return (low + (high - low) / 2);
    }
}
