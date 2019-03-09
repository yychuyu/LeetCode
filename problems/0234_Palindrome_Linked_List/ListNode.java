package com.list;

import java.util.Arrays;

public class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
    }
}

class Solution {
    public boolean isPalindrome(ListNode head) {
        if (head == null || head.next == null)
            return true;

        ListNode slow = head;
        ListNode fast = head;
        while (fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        slow = slow.next;
        ListNode pre = null;
        ListNode reHead = slow;
        while (slow != null){
            reHead = slow.next;
            slow.next = pre;
            pre = slow;
            slow = reHead;
        }


        while (head != null && pre != null) {
            if (head.val != pre.val)
                return false;
            head = head.next;
            pre = pre.next;
        }

        return true;
    }

    public static int[] stringToIntegerArray(String input) {
        input = input.trim();
        input = input.substring(0, input.length());
        if (input.length() == 0) {
            return new int[0];
        }
        String[] parts = input.split(",");
        int[] output = new int[parts.length];
        for (int index = 0; index < parts.length; index++) {
            String part = parts[index].trim();
            output[index] = Integer.parseInt(part);
        }
        return output;
    }

    public static ListNode stringToListNode(String input) {
        // Generate array from the input
        int[] nodeValues = stringToIntegerArray(input);

        // Now convert that list into linked list
        ListNode dummyRoot = new ListNode(0);
        ListNode ptr = dummyRoot;
        for (int item : nodeValues) {
            ptr.next = new ListNode(item);
            ptr = ptr.next;
        }
        return dummyRoot.next;
    }

    public static String booleanToString(boolean input) {
        return input ? "True" : "False";
    }

    public static void main(String[] args) {
        String line = "1, 1, 2, 1";
        ListNode head = stringToListNode(line);

        boolean ret = new Solution().isPalindrome(head);

        String out = booleanToString(ret);

        System.out.print(out);

    }
}


