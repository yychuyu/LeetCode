public class Main {

    public static void main(String[] args) {
//        ListNode t1 = new ListNode(2);
////        t1.next = new ListNode(4);
////        t1.next.next = new ListNode(3);
////        ListNode t2 = new ListNode(5);
////        t2.next = new ListNode(6);
////        t2.next.next = new ListNode(4);
        ListNode t1 = new ListNode(5);

        ListNode t2 = new ListNode(5);

        addTwoNumbers(t1, t2);
    }

    public static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int carry = 0;
        ListNode p, head = new ListNode(0);
        p = head;
        while(l1 != null || l2 != null || carry != 0) {
            if (l1 != null) {
                carry += l1.val;
                l1 = l1.next;
            }
            if (l2 != null) {
                carry += l2.val;
                l2 = l2.next;
            }
            p.next = new ListNode(carry%10);
            carry /= 10;
            p = p.next;
        }
        return head.next;
    }
//    public static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
//        ListNode head, tmp;
//        //计算链表第一个数字
//        int carry = 0;
//        int add_num = (l1.val + l2.val + carry) % 10;
//        carry = (l1.val + l2.val + carry) / 10;
//        head = new ListNode(add_num);
//        tmp = head;
//        l1 = l1.next;
//        l2 = l2.next;
//        //计算所有数字
//        while (l1 != null && l2 != null) {
//            add_num = (l1.val + l2.val + carry) % 10;
//            carry = (l1.val + l2.val + carry) / 10;
//            head.next = new ListNode(add_num);
//            head = head.next;
//            l1 = l1.next;
//            l2 = l2.next;
//        }
//        while (l1 != null) {
//            add_num = (l1.val + carry) % 10;
//            carry = (l1.val + carry) / 10;
//            head.next = new ListNode(add_num);
//            head = head.next;
//            l1 = l1.next;
//        }
//        while (l2 != null) {
//            add_num = (l2.val + carry) % 10;
//            carry = (l2.val + carry) / 10;
//            head.next = new ListNode(add_num);
//            head = head.next;
//            l2 = l2.next;
//        }
//        if (carry != 0)
//            head.next = new ListNode(carry);
//        return tmp;
//    }
}
