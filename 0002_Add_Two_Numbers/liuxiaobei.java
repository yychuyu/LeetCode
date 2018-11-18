package test;

/**
 * Created with IntelliJ IDEA.
 * Description:
 *
 * @author: liuxiaobei
 * @Date: 2018-11-06
 * @Time: 23:03
 */
public class liuxiaobei {

    public static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode c1 = l1;
        ListNode c2 = l2;
        ListNode sentinel = new liuxiaobei().new ListNode(0);
        ListNode d = sentinel;
        int sum = 0;
        while (c1 != null || c2 != null) {
            sum /= 10;
            if (c1 != null) {
                sum += c1.val;
                c1 = c1.next;
            }
            if (c2 != null) {
                sum += c2.val;
                c2 = c2.next;
            }
            d.next = new liuxiaobei().new ListNode(sum % 10);
            d = d.next;
        }
        if (sum / 10 == 1)
            d.next = new liuxiaobei().new ListNode(1);
        return sentinel.next;
    }

    class ListNode {
      int val;
      ListNode next;
      ListNode(int x) { val = x; }
    }

    public static void main(String[] args) {

        // 创建两个链表
        // 第一个链表:  2-> 4 -> 3 (在做加法运算代表的是342)
        ListNode l1 = new liuxiaobei().new ListNode(2);  // 这是第一个链表的第一个节点(不能用这个节点去往下加数据)
        // 必须有一个指针去往第一个节点上去加数据
        ListNode p = l1;  // 这个指针节点会从链表的第一个节点一直往下走(直至最后一个节点)
        p.next = new liuxiaobei().new ListNode(4);
        p = p.next;
        p.next = new liuxiaobei().new ListNode(3);

        // 第二个链表
        ListNode l2 = new liuxiaobei().new ListNode(5);
        ListNode q = l2;
        q.next = new liuxiaobei().new ListNode(6);
        q = q.next;
        q.next = new liuxiaobei().new ListNode(4);

        ListNode re = addTwoNumbers(l1, l2);
        while(re != null) {
            System.out.println(re.val);
            re = re.next;
        }
    }

}
