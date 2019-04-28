    bool isHappy(int n) {
        int digit = 0;
        int num = n;
        while(true) // calculate the number of digits - 1
            if(num/10 > 0){
                ++digit;
                num = num / 10;
            } else {
                break;
            }
        }
        if(digit == 0){ //if there is only 1 digit
            if(n == 1 || n ==7) return true;
            else return false;
        } else {// if there are momre than 1 digit
            int sum = 0;
            int number[digit+1] = {0};
            for(int i = 0; i <= digit; ++i){//break down the number into digits
                number[i] = n % 10;
                n /= 10;
            }
             for(int j = 0; j <= digit; ++j){//find the sum
                sum += pow(number[j],2);
            }
            return isHappy(sum);//recurse onto it
        }
    }
