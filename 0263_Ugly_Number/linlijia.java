class Solution {
    
    public boolean isUgly(int num) {
           
           if (num == 0)  
               return false; 
        
            while (num % 2 == 0) {
                num = num >> 1;
            }
             while (num % 3 == 0) {
                num = num / 3;
            }
             while (num % 5 == 0) {
                num = num / 5;
            }
                       
          return num == 1 ? true : false;

    }
    
    
}