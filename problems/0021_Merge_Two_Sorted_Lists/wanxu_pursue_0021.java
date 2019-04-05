/**
 * @Author: Json Wan
 * Created at: 2019/3/13.
 * Description:
 * Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
Example:
Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
 思路：
1.最简单的做法：遍历两个表归并merge即可；
2.曾在面试中遇到过，要求不占用额外空间，就地合并，通过更改两个链表中的指针指向实现；
 */
class ListNode {
    int val;
    ListNode next;
    ListNode(int x) {
        val = x;
    }
}

public class wanxu_pursue_0021 {

    //算法空间可继续把起始的那一个省掉，意义不大，时间复杂度上已足够简洁
    //AC,1.00,Nice!!!
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode pHead=new ListNode(0);
        ListNode pHeadBak=pHead;
        while(l1!=null&&l2!=null){
            if(l1.val<l2.val){
                pHead.next=l1;
                l1=l1.next;
            }else {
                pHead.next=l2;
                l2=l2.next;
            }
            pHead=pHead.next;
        }
        if(l1!=null){
            pHead.next=l1;
        }else{
            pHead.next=l2;
        }
        return pHeadBak.next;
    }


    public void printList(ListNode root){
        while(root!=null){
            System.out.print(root.val);
            root=root.next;
            if(root!=null){
                System.out.print("-->");
            }
        }
        System.out.println();
    }

    public static void main(String[] args) {
        ListNode root11=new ListNode(1);
        ListNode root12=new ListNode(2);
        ListNode root13=new ListNode(4);
        root11.next=root12;
        root12.next=root13;
        ListNode root21=new ListNode(1);
        ListNode root22=new ListNode(3);
        ListNode root23=new ListNode(4);
        root21.next=root22;
        root22.next=root23;
        wanxu_pursue_0021 instance=new wanxu_pursue_0021();
        instance.printList(root11);
        instance.printList(root21);
        instance.printList(instance.mergeTwoLists(null,root21));
        instance.printList(instance.mergeTwoLists(root11,null));
        instance.printList(instance.mergeTwoLists(root11,root21));
    }
}
