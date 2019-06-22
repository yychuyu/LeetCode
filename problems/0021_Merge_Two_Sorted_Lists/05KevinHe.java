public class Main {

    public static void main(String[] args) {
        ListNode t1 = new ListNode(1);
        t1.next = new ListNode(3);
        ListNode t2 = new ListNode(2);
        t2.next = new ListNode(4);
        mergeTwoLists(t1, t2);
    }

    public static ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if (l1 == null) return l2;
        if (l2 == null) return l1;
        if (l1.val <= l2.val){
            l1.next = mergeTwoLists(l1.next,l2);
            return l1;
        }else{
            l2.next = mergeTwoLists(l1,l2.next);
            return l2;
        }
    }
}
//    public static ListNode mergeTwoLists(ListNode l1, ListNode l2) {
//        ListNode tmp = new ListNode(-1);
//        ListNode p = tmp;
//        while(l1!=null && l2!=null){
//            if(l1.val < l2.val){
//                tmp.next = new ListNode(l1.val);
//                l1 = l1.next;
//                tmp = tmp.next;
//            }else{
//                tmp.next = new ListNode(l2.val);
//                l2 = l2.next;
//                tmp = tmp.next;
//            }
//        }
//        if(l1!=null) tmp.next = l1;
//        if(l2!=null) tmp.next = l2;
//        return p.next;
//    }
