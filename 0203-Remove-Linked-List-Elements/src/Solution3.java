/**
 * @author Dell
 * @create 2018-10-13 17:46
 */
public class Solution3 {

    public ListNode removeElements(ListNode head, int val) {
        if (head == null)
            return null;

        ListNode ret = removeElements(head.next, val);
        if (head.val == val)
            return ret;

        else {
            head.next = ret;
            return head;
        }

    }

    public static void main(String[] args) {
        int[] nums = {1, 2, 6, 3, 4, 5, 6};
        ListNode head = new ListNode(nums);
        System.out.println(head);

        ListNode res = (new Solution3()).removeElements(head, 6);
        System.out.println(res);
    }
}
