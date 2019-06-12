class Solution {
    public String reverseWords(String s) {
        // write your code here
        if(s.length() == 0 || s == null){
            return "";
        }
        //按照空格将s切分
        String[] array = s.split(" ");
        StringBuilder sb = new StringBuilder(s.length()<<1);
        //从后往前遍历array，在sb中插入单词
        for(int i = array.length - 1; i >= 0; i--){
            if(!array[i].equals("")) {
                if (sb.length() > 0) {
                    sb.append(" ");
                }
                
                sb.append(array[i]);
            }
        }
        return sb.toString();
    }
}
