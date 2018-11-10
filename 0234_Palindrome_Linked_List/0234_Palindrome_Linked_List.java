/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */

/**
*微信号： VINO
*
*将链表的后半部分进行反转，将第一个节点和后半部分第一个节点进行比较，直到链表末尾
*不考虑题目要求 先想到用栈来实现
*同样的思路 求链表长度再取半 在C++里面超时了。。后转过来用Java写反而过了。。。。
*/

class Solution {
    public boolean isPalindrome(ListNode head) {
        if(head == null){
            return true;
        }
        
        int length = 0;
        ListNode temp = head, count = head;//temp移动到中间节点，count用于计算长度
        while(count != null){
            count = count.next;
            length++;
        }//计算长度
        
        for(int i=0;i<length/2;i++){
            temp = temp.next;
        }//将temp移动到中间节点
    
        ListNode nextNode = temp.next;//下一节点
        ListNode r = nextNode;//用来保存下一节点的下一节点 交换当前节点和下一节点
        while(nextNode!= null){
            r = nextNode.next;
            nextNode.next = temp;
            temp = nextNode;
            nextNode = r;
        }//反转
        
        for(int i=0;i<length/2;i++){
            if(head.val != temp.val)
                return false;
            head = head.next;
            temp = temp.next;
        }//比较value
        
        return true;
    }
}