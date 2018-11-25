package com.company.page2;

import java.util.HashMap;
import java.util.Map;
import java.util.TreeMap;

public class Main61 {
    public static void main(String[] args){
        Main61 main = new Main61();
        main.test();
    }

    private void test() {
        ListNode listNode = new ListNode(1);
        listNode.next = new ListNode(2);
        listNode.next.next = new ListNode(3);
        listNode.next.next.next = new ListNode(4);
        listNode.next.next.next.next = new ListNode(5);
        ListNode rotateNode = rotateRight(listNode,2);
        while (rotateNode!=null) {
            System.out.print(rotateNode.val + "->");
            rotateNode = rotateNode.next;
        }
        System.out.println("null");
    }

    public ListNode rotateRight(ListNode head, int k) {
        ListNode tmpNode = head;
        int size = 0;
        while (tmpNode!=null){
            size++;
            tmpNode = tmpNode.next;
        }
        int rotateSize = k%size;
        tmpNode = head;
        Map<Integer,ListNode> listNodeMap = new TreeMap<>();
        int pos = 0;
        while (tmpNode!=null){
            listNodeMap.put((pos+rotateSize)%size,tmpNode);
            tmpNode = tmpNode.next;
            pos++;
        }
        ListNode headNode = new ListNode(0);
        ListNode p = headNode;
        for (Map.Entry<Integer,ListNode> entry:listNodeMap.entrySet()){
            headNode.next = entry.getValue();
            headNode = headNode.next;
        }
        headNode.next = null;
        return p.next;
    }

    public class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
    }
}
