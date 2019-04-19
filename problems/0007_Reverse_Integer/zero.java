
class Solution {
    public int reverse(int x) {
        int remainder;
        int result = 0;
        long resultCope = 0;
        while (x / 10 != 0){
            remainder = x % 10;
            x = x / 10;
            result = result * 10 + remainder * 10;
            resultCope = resultCope * 10 + remainder * 10;
        }
        result += x;
        resultCope += x;
        if(resultCope != result){
            return 0;
        }
        return result;
    }
}