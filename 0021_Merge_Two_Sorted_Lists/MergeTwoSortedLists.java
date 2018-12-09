public class MergeTwoSortedLists {

    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if (l1 == null) return l2;
        if (l2 == null) return l1;
        ListNode head = (l1.val < l2.val) ? l1 : l2;
        ListNode nonhead = (l1.val < l2.val) ? l2 : l1;
        head.next = mergeTwoLists(head.next, nonhead);
        return head;
    }
}
This file is added by Chenghui
