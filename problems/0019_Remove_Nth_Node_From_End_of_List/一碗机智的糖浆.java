class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        //dummy链表指向head
        ListNode dummy=new ListNode(0);
        dummy.next=head;
        int length=0;
        //创建一个新链表
        ListNode first=head;
        //遍历链表长度
        while(head!=null){
            length++;
            head=head.next;
        }
        //链表末尾第n个数,length是一会要遍历的个数
        length -= n;
        first=dummy;
        //只要length不是0，就一直走下去，直到到达目的索引
        while(length>0){
            length--;
            first=first.next;
        }
        //跳过要删除的节点
        first.next=first.next.next;
        return dummy.next;
    }
}