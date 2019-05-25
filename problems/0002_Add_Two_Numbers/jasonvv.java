class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        if(l1==null)return l1;
        if(l2==null)return l2;
        ListNode head = null;
        int ext = 0;
        ListNode newL =new  ListNode(0);
        ListNode curr = newL;
        while(l1!=null||l2!=null){
            int x = (l1!=null)?l1.val:0;
            int y = (l2!=null)?l2.val:0;
            int sum = ext + x + y;//ext就是需要进位的值
            ext = sum / 10;
            curr.next = new ListNode(sum%10);
            curr = curr.next;
            if(l1!=null) l1 = l1.next;
            if(l2!=null) l2 = l2.next;
        }
        
        if(ext > 0 ){
            curr.next = new ListNode(ext);
        }
        return newL.next;
    }
}
