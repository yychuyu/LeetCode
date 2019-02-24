public class CycleNumber {
    public static void main(String args[]) {
        int n = 20;
        int count = ComputedNumber(n);
        System.out.println(count);
    }
    public static int ComputedNumber(int N){
        int count = 0;
        for (int i = 1; i <= N; i++) {
            String str = String.valueOf(i);
            Boolean status = (str.contains("2")||str.contains("5")||str.contains("6")||str.contains("9"))
                    &&(!str.contains("3")&&!str.contains("4")&&!str.contains("7"));
            if(status) {
                count++;
            }
        }
        return count;
    }
}
