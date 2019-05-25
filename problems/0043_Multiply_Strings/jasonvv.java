class Solution {
    public String multiply(String num1, String num2) {
        StringBuilder res = new StringBuilder();
        char[] a = num1.toCharArray();
        char[] b = num2.toCharArray();
        if ((num1.length()==1&&num1.equals("0"))||(num2.length()==1&&num2.equals("0"))) return "0";
        int[] result = new int[a.length + b.length];
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < b.length; j++) {
                result[a.length - i + b.length - j - 2] += (a[i] - '0') * (b[j] - '0');
            }
        }
        for (int i = 0; i < result.length - 1; i++) {
            if (result[i] >= 10) {
                result[i + 1] += result[i] / 10;
                result[i] = result[i] % 10;
            }
        }
        boolean flag = false;
        for (int i = result.length - 1; i >= 0; i--) {
            if (result[i] != 0) {
                flag = true;
            }
            if (flag) {
                res.append(result[i]);
            }
        }
        return res.toString();
    }
}
