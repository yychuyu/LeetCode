class Solution {
    public String reverseWords(String s) {
        StringBuilder sb = new StringBuilder();
        String[] items = s.split(" ");
        for (int i = 0; i < items.length; i++) {
            if(i == items.length - 1){
                //sb.append(new StringBuilder(items[i]).reverse().toString());
				sb.append(reverseString(items[i]));
            }else{
                //sb.append(new StringBuilder(items[i]).reverse().toString() + " ");
				sb.append(reverseString(items[i]) + " ");
            }
        }
        return sb.toString();
    }
	//发现自己写的 reverse 方法效率更高；
    public String reverseString(String str){
        char[] chars = str.toCharArray();
        for (int i = 0; i < chars.length / 2; i++) {
            char tmp = chars[i];
            chars[i] = chars[chars.length - 1 - i];
            chars[chars.length - 1 - i] = tmp;
        }
        return new String(chars, 0, chars.length);
    }
}