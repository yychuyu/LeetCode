class Solution {
    public double myPow(double x, int n) {
    	boolean isNagetive = false;
    	if( n<0 ) {
    		n = -n;
    		isNagetive = true;
    	}
    	if( isNagetive ) {
    		return 1/pow(x, n);
    	}else {
    		return pow(x, n);
    	}
    }
    public static double pow(double x, int n) {
    	double res = 1.0;
		if( n==0 ) {
			return 1.0;
		}else if( n==1 ) {
			return x;
		}else if( n%2==0 ) {
			res = pow(x*x, n/2);
		}else{
			res = pow(x*x, n/2) * x;
		}
		return res;
	}
}
