class Solution {
    public int rotatedDigits(int N) {
        int sum = 0;
        for(int i = 1; i <= N; i++){
            if(isGoodNum(i)){
                sum += 1;
            }
        }
        return sum;
    }
    
    private boolean isGoodNum(int num) {
        while (true) {
            int x = num / 10;
            if (x > 0 && x < 10) {
                int y = num % 10;
                if (x == 2 || x == 5 || x == 6 || x == 9)  {
                    if(y != 3 && y != 4 && y != 7){
                        return true;
                    }else{
                        return false;
                    }
                } else if (x == 3 || x == 4 || x == 7) {
                    return false;
                } else {
                    if (y == 2 || y == 5 || y == 6 || y == 9){
                        return true;
                    }else{
                        return false;
                    }
                }
            } else if (x >= 10) {
                int y = num % 10;
                if (y == 3 || y == 4 || y == 7) {
                    return false;
                }else if (y == 2 || y == 5 || y == 6 || y == 9){
                    while (true) {
                        int z = x % 10;
                        if (z == 3 || z == 4 || z == 7) {
                            return false;
                        }
                        if (x == 0 && z == 0) {
                            return true;
                        }
                        x /= 10;
                    }
                }
                num /= 10;
            } else if (x == 0) {
                int y = num % 10;
                if (y == 2 || y == 5 || y == 6 || y == 9) {
                    return true;
                } else {
                    return false;
                }
            }
        }
    }
}