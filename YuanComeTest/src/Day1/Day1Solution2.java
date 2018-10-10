package Day1;

/*
给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

示例 1:

输入: 1->1->2
输出: 1->2
示例 2:

输入: 1->1->2->3->3
输出: 1->2->3
*/
/*
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */

/**
 * @author THY
 * @date 2018/10/9
 */
public class Day1Solution2 {
    public ListNode deleteDuplicates(ListNode head) {
        //和第一题类似，只是从数组换成了链表,返回的是链表不是链表长度
        ListNode currentNode = head;
        while(currentNode != null && currentNode.next != null) {
            if (currentNode.val == currentNode.next.val) {
                //如果相等则指针跳过当前节点的下一节点
                currentNode.next = currentNode.next.next;
            }else {
                currentNode = currentNode.next;
            }
        }
        return head;
    }
    //题目定义的ListNode
    class ListNode {
        int val;
        ListNode next;
        ListNode(int x) {
            val = x;
        }
    }
}

