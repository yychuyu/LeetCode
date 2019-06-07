public class Main {

    public static void main(String[] args) {
        System.out.println(myAtoi("9223372036854775808"));
    }
    public static int myAtoi(String str) {
        str = str.trim();
        boolean flag = true;
        long results = 0;
        for(int i = 0 ;i<str.length();i++){
            if(i==0 && str.charAt(0) == '-') {
                flag = false;
                continue;
            }
            if(i==0 && str.charAt(0) == '+') {
                continue;
            }
            if(str.charAt(i)>='0' && str.charAt(i)<='9'){
                results = (results * 10) + (str.charAt(i)-'0');

            }else{
                break;
            }
            if(results>Integer.MAX_VALUE && flag ==true)  return Integer.MAX_VALUE;
            else if(results>Integer.MAX_VALUE && flag ==false)  return Integer.MIN_VALUE;
        }
        return (int) (flag==true?results:-results);
    }
}
