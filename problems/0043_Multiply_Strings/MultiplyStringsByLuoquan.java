import java.util.Arrays;

public class MultiplyStringsByLuoquan {
    public static String multiply(String num1, String num2) {
        if (null == num1 || null == num2)
            return "-1";
        int m = num1.length(), n = num2.length();
        int[] res = new int[m + n];

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int mul = (num1.charAt(i) - '0')
                        * (num2.charAt(j) - '0');
                int p1 = i + j, p2 = i + j + 1;
                int sum = mul + res[p2];

                res[p1] += sum / 10;
                res[p2] = (sum) % 10;
            }
        }

        StringBuilder sb = new StringBuilder();
        boolean trim = true;
        for (int c : res) {
            if(0 == c && trim){
                continue;
            }
            sb.append(c);
            trim = false;
        }
        return 0 == sb.length()?"0":sb.toString();
    }

}
