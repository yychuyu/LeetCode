class Solution {
    public int countPrimes(int n) {
        if (n < 3) 
            return 0;

        int cnt = n / 2;
        boolean[] flag = new boolean[n];
        
        for (int i = 3; i * i < n; i += 2) {
          if (!flag[i]) {
              for (int j = i * i; j < n; j += 2 * i) {
                  if (!flag[j]) {
                    flag[j] = true;
                    cnt--;
                  }
              }
          }        
        }
        
                return cnt;
    }
}