package com.example.jetpackuse;

import java.util.Arrays;

//Number of Lines to Write String
public class L_Solution {

    public static void main(String[] args){
       int[] widths=new int[]{4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
       String S="bbbcccdddaaa";
       System.out.print(Arrays.toString(numberoflines(widths,S)));
    }

    public static int[] numberoflines(int[] widths,String S){
        int maxline=1;
        int max=0;
        for(int i=0;i<S.length();i++){
            char c=S.charAt(i);
            int cw=widths[c-97];
            if((max+cw)<=100){
                max+=cw;
            }else {
                maxline++;
                max=cw;
            }
        }
        int[] a=new int[2];
        a[0]=maxline;
        a[1]=max;
        return a;
    }
}
