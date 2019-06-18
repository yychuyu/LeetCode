package com.company;

public class Main {

    public static void main(String[] args) {
        // write your code here
        reverseWords("kevin he's chinese name");
    }

    //    public String reverseWords(String s)  {
//        String []splits = s.split(" ");
//        StringBuilder sb = new StringBuilder();
//        for(int i=0;i<splits.length;i++){
//            sb.append(new StringBuilder(splits[i]).reverse().toString());
//            sb.append(" ");
//        }
//        return sb.toString().substring(0,sb.toString().length()-1);
//    }
    public static String reverseWords(String s) {
        char[] chars = s.toCharArray();
        int startIndex = 0;
        while (startIndex < s.length()) {
            int endIndex = s.indexOf(' ', startIndex + 1);
            if (endIndex == -1) {
                endIndex = s.length();
            }
            reverse(startIndex, endIndex, chars);
            startIndex = endIndex + 1;
        }
        return String.valueOf(chars);
    }

    private static void reverse(int startIndex, int endIndex, char[] chars) {

        for (int i = startIndex, k = endIndex - 1; i < k; i++, k--) {
            char temp = chars[i];
            chars[i] = chars[k];
            chars[k] = temp;
        }
    }
//    public String reverseWords(String s) {
//        int start = 0,end = 0,n = s.length();
//        char[] arr = s.toCharArray();
//        while(start<n && end<n){
//            while(end<n && arr[end]!=' ') end++;
//            int i = start,j = end-1;
//            while(i<j){
//                char temp = arr[i];
//                arr[i] = arr[j];
//                arr[j] = temp;
//                i++;
//                j--;
//            }
//            start = ++end;
//        }
//        return new String(arr);
//    }
}
