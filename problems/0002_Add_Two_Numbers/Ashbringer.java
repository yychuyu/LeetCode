/**
 * @Author 宋宗垚
 * @Date 2018/12/11 17:51
 * @Description 2. 两数相加
 */
/*
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
 */
public class Ashbringer {

    public static void main(String[] args){
        ListNode l1 = new ListNode(5);
        ListNode l2 = new ListNode(5);
        addTwoNumbers(l1,l2);
    }
    public static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        if(l1==null && l2==null){
            return null;
        }else if(l1==null && l2!=null) {
            return l2;
        }else if(l1!=null && l2==null){
            return l1;
        }
        int sum = l1.val+l2.val;
        int v = sum;
        if(sum>=10){
            v = sum-10;
        }
        ListNode result = new ListNode(v);
        ListNode temp = result;
        while (true){

            if(l1.next==null&&l2.next==null){
                if(sum<10){
                    break;
                }else {
                    l1.next =  new ListNode(0);
                }

            }
            if(l1.next==null && l2.next!=null){
                l1.next = new ListNode(0);
            }else if(l2.next==null && l1.next!=null){
                l2.next = new ListNode(0);
            }

            if(sum>=10){
                sum = l1.next.val+l2.next.val+1;
            }else {
                sum = l1.next.val+l2.next.val;
            }
            v = sum;
            if(sum>=10){
                v = sum-10;
            }
            ListNode a = new ListNode(v);
            temp.next = a;
            l1 = l1.next;
            l2 = l2.next;
            temp = temp.next;
        }

        return result;

    }

}
