class Solution {
    public static final String TWO = "2";
    public static final String THREE = "3";
    public static final String FOUR = "4";
    public static final String FIVE = "5";
    public static final String SIX = "6";
    public static final String SEVEN = "7";
    public static final String NINE = "9";

    public static final Integer startNumber = 1;
    public static final Integer endNumber = 10000;
    
    public int rotatedDigits(int N) throws Exception {
        int testCount = 4;
        Integer testNum = N;
        if (testNum < startNumber || testNum > endNumber){
            throw new Exception("请输入要求区间内的合法数字");
        }
        /** 从数字11开始计算，前10位包含的好数数量是确定的 */
        for (int i = 11; i < (testNum - 1) ; i++) {
            String s = String.valueOf(i);
            /** 进行数字过滤，包含3,4,7的一定不是好数 */
            if ((s.contains(THREE)
                    || s.contains(FOUR)
                    || s.contains(SEVEN)
            )){
                continue;
            }
            /** 旋转数字并进行拼接 */
            char[] chars = s.toCharArray();
            StringBuilder sb = new StringBuilder();
            for (char aChar : chars) {
                String s1 = String.valueOf(aChar);
                switch (s1){
                    case TWO:
                        s1 = FIVE;
                        break;
                    case FIVE:
                        s1 = TWO;
                        break;
                    case SIX:
                        s1 = NINE;
                        break;
                    case NINE:
                        s1 = SIX;
                        break;
                    default:
                        break;
                }
            sb.append(s1);
            }
            /** 当旋转之后的数字与旋转前的数字相同时，直接跳过 */
            if (sb.toString().equals(s)){
                continue;
            }
            testCount++;
    }
   return testCount;     
}
    
}

public class MainClass {
    public static void main(String[] args) throws Exception {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String line;
        while ((line = in.readLine()) != null) {
            int N = Integer.parseInt(line);
            
            int ret = new Solution().rotatedDigits(N);
            
            String out = String.valueOf(ret);
            
            System.out.print(out);
        }
    }
}