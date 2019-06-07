package com.company;

public class Main {

    public static void main(String[] args) {
        // write your code here

//        System.out.println(multiply("89","99"));
        String []ss = "sss ss".split(" ");
        int i = 3;
    }

    public static String multiply(String num1, String num2) {
        //1. 将字符串转为字符数组，更方便操作
        char[] nums1 = num1.toCharArray();
        char[] nums2 = num2.toCharArray();
        int n = nums1.length, m = nums2.length, i, j, k;
        //2.两个数相乘，其最大位数也不会大于两个数的位数之和
        int[] result = new int[m + n];
        //3.将字符数组转换为数字数组
        for (i = 0; i < n; i++)
            nums1[i] -= '0';
        for (j = 0; j < m; j++)
            nums2[j] -= '0';
        //4.用nums2的每一位去乘以Nums1，并累加到result。模拟手写乘法。
        for (i = 0; i < m; i++) {
            int carry = 0;
            //4.1处理当前位置的数字
            for (j = 0; j < n; j++) {
                result[i + j] = result[i + j] + nums2[m - 1 - i] * nums1[n - 1 - j] + carry;
                carry = result[i + j] / 10;
                result[i + j] %= 10;
            }
            k = i + j;
            //4.2处理进位
            while (carry != 0) {
                result[k] += carry;
                carry = result[k] / 10;
                result[k] %= 10;
                k++;
            }
        }
        //5.将字符数组转为字符串
        StringBuilder tmp = new StringBuilder(n + m);
        i = m + n - 1;
        while (i > 0 && result[i] == 0)
            i--;
        while (i >= 0)
            tmp.append(result[i--]);
        return tmp.toString();
    }
}
