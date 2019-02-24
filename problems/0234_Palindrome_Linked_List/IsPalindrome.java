/**
 * * @Description
 * *反转后半部分后于前半部分比较是否为回文链表
 * * @Author 22k
 * * 微信 rp8430177
 * * @Email 8430177@qq.com
 * * @Date 2018-11-10 13:19
 **/
public boolean isPalindrome(ListNode head) {
    ListNode last = head, middle = head;
	//将middle,last分别移动到链表中间和末尾
    while (last != null && last.next != null) {
        last = last.next.next;
        middle = middle.next;
    }
	//将后半部分反转
    middle = reverse(middle);
    last = head;
	//比较是否为回文链表
    while (middle != null) {
        if (last.val != middle.val) {
            return false;//不是回文链表，返回false
        }
        last = last.next;
    }
    return true;
}
//反转链表
public ListNode reverse(ListNode head) {
    ListNode pre = null;
    while (head != null) {
        ListNode next = head.next;
        head.next = pre;
        pre = head;
        head = next;
    }
    return pre;
}