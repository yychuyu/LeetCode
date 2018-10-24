import java.util.Scanner;

public class nicefuture {

    int pick;

    public static void main(String[] args) {
        nicefuture begin = new nicefuture();
        begin.begin();
    }

    public void begin() {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        this.pick = scanner.nextInt();
        System.out.println(this.guessNumber(n));
    }

    public int guess(int n) {
        if (n == this.pick) {
            return 0;
        } else if (pick < n) {
            return -1;
        } else {
            return 1;
        }
    }

    /*----------------------------------------------*/
    public int guessNumber(int n) {
        long lower = 1, ceiling = n;  //n的数值不会超过int，但是middle和ceiling的和就有可能超过int了。数据溢出就很可能为负，进入死循环。
        int result = 0, middle = (int)((1+n)/2);
        
        while ((result = guess(middle)) != 0) {
            if (result == -1) ceiling = middle-1;
            else lower = middle+1;
            middle = (int)((lower+ceiling)/2);
        }
        
        return middle;
    }
    /*-----------------------------------------------*/
}
