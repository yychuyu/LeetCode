/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        
        ListNode result = new ListNode(0);//头结点
        ListNode temp = result;
        ListNode zero = new ListNode(0);
        
        while(l1 != zero || l2 != zero){//循环相加
            temp.next = addSingle(l1,l2);
            temp = temp.next;
            l1 = l1.next != null ? l1.next : zero;//值为零
            l2 = l2.next != null ? l2.next : zero;//值为零
        }
        
        if(flag){//最终进位
            temp.next = new ListNode(1);
        } 
        
        return result.next;//不要头      
    }
    
    //单节点相加函数
    boolean flag = false;//进位标志
    ListNode addSingle(ListNode a, ListNode b){
        int result =  flag ? a.val + b.val + 1 : a.val + b.val; //包含进位运算
        
        if(result >= 10){//进位判断
            flag = true; //进位
        }else{
            flag = false; //置空进位
        }
        
        return new ListNode(result%10);//返回本位结果
    }
    
}