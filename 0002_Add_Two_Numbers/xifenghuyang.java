import java.lang.reflect.Array;

/**
 *
 */

package test;

public class xifenghuyang {
    public static ListNode addTwoNumbers(ListNode l1, ListNode l2){
        ListNode c1 = l1; //c1指针指向l1
        ListNode c2 = l2; //c2指针指向l2
        ListNode sentinel = new xifenghuyang().new ListNode(0); //创建头存储
        ListNode d = sentinel; //d指向结果
        int sum = 0;
        while (c1 != null || c2 != null){
            sum /= 10;  // 取进位后的数字，即当前位
            if(c1 != null){
                sum += c1.val;
            }
            if(c2 != null){
                sum += c2.val;
            }
            d.next = new xifenghuyang().new ListNode(sum % 10); //取余数
            d = d.next; //d指针指向新创建的存储对象。
        }
        // 解决最后输入的数字和超过10，而仅有sum产生的进位问题，
        if(sum /10 ==1){
            d.next = new xifenghuyang().new ListNode(1);
        }
        return sentinel.next;
    }

    class ListNode {
        int val;
        ListNode next;
        ListNode(int x){ val = x;}
    }

    public static void main(String[] args){
//        创建第一个链表 2->4->3
        int[] list1 = {2, 4, 3};
        ListNode l1 = new xifenghuyang().creatList(list1);
//        创建第二个链表  5->->4
        int[] list2 = {5, 6,4};
        ListNode l2 = new xifenghuyang().creatList(list2);

        ListNode result = addTwoNumbers(l1, l2);
        while(result!=null){
            System.out.println(result.val);
            result = result.next;
        }

    }

    public ListNode creatList(int[] listValue) {
        ListNode result = new xifenghuyang().new ListNode(0);
        ListNode pointer = result;
        for (int i = 0; i < listValue.length; i++) {
            pointer.next = new xifenghuyang().new ListNode(listValue[i]);
            pointer = pointer.next;
        }
        return result.next;
    }
}
