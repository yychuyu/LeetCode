package leetcodePart5;

import LeetCodePart4.ListNode;

/**
 * @author 刘云生
 * @date 2019/4/917:31
 */
public class NO203_liuyunsheng {
    public static void main(String[] args) {
        ListNode listNode=initListNode.init();
        System.out.println(NO203_liuyunsheng.removeElement(listNode,6));
    }
    public static ListNode removeElement(ListNode head, int val){
        ListNode header = new ListNode(-1);
        header.next = head;
        ListNode cur = header;
        while(cur.next != null){
            if(cur.next.val == val ){
                cur.next = cur.next.next;
            }else{
                cur = cur.next;
            }
        }
        return header.next;
    }
    
}
