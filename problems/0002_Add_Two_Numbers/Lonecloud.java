

public class Lonecloud{
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
       return calSum(l1,l2,0);
    }

    /**
     * 循环处理该问题，可以使用while/递归
     * @param l1
     * @param l2
     * @param recent
     * @return
     */
    public ListNode calSum(ListNode l1, ListNode l2,int recent){
        ListNode listNode;
        if (l1==null&&l2==null){
            //判断recent是否为0
            if (recent==0){
                return null;
            }else {
                return new ListNode(recent);
            }
        }
        //判断这两个是否为0的情况
        l1=l1==null?new ListNode(0):l1;
        l2=l2==null?new ListNode(0):l2;
        //累加
        recent=l1.val+l2.val+recent;
        //赋值
        int val=recent%10;
        listNode=new ListNode(val);
        listNode.next = calSum(l1.next, l2.next, recent / 10);
        return listNode;
    }
}


class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}