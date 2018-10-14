/**
 * @author Dell
 * @create 2018-10-13 15:59
 */
public class ListNode {

    int val;
    ListNode next;
    ListNode(int x) { val = x; }

    public ListNode(int[] arr) {
        if (arr == null || arr.length == 0)
            throw new IllegalArgumentException("arr can not be empty.");

        //链表节点的构造函数
        //使用arr为参数，创建一个链表，当前的ListNode为链表头结点
        this.val = arr[0];
        ListNode cur = this;
        for (int i = 1; i < arr.length; i++) {
            cur.next = new ListNode(arr[i]);
            cur = cur.next;
        }
    }

    //以当前节点为头结点的链表信息字符串
    public String toString() {

        StringBuilder s = new StringBuilder();
        ListNode cur = this;
        while (cur != null) {
            s.append(cur.val + "->");
            cur = cur.next;
        }
        s.append("NULL");
        return s.toString();
    }

}