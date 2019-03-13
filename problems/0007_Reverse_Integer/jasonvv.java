class Solution {
    public int reverse(int x) {
        long z = x;
        String str = String.valueOf(Math.abs(z));
        StringBuilder conStr = new StringBuilder();
        int len = str.length();
        while(len > 0){
             conStr.append(str.charAt(len - 1));
             len--;
        }
        Long l = Long.parseLong(conStr.toString());
        if(l > Integer.MAX_VALUE){
            return 0;
        }
        if(x >= 0)
            return l.intValue();
        else{
            return -l.intValue();
        }
    }
}
