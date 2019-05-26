/**
 * @Author: Json Wan
 * Created at: 2019/3/14.
 * Description:
 * 23. Merge k Sorted Lists
Hard
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
Example:
Input:
[
1->4->5,
1->3->4,
2->6
]
Output: 1->1->2->3->4->4->5->6
 思路：
 1.最简单的做法：k路归并；
 2.若不占用额外空间，就地合并，参考两路的算法，类似；
 3.可以优化的地方是可以构建一个小顶堆，每次遍历k个头结点找出最小的一个这个操作是可以重复利用的，将复杂度为k的遍历转为logk的堆调整，最终复杂度为nlogk；
 4.最优做法：转化为多个二路归并。
 */
class ListNode {
    int val;
    ListNode next;
    ListNode(int x) {
        val = x;
    }
}
public class wanxu_pursue_0023 {

    //归并的思想，转化为多个二路归并，优秀！
    public ListNode bestMergeKLists(ListNode[] lists) {
        if (lists == null || lists.length == 0) {
            return null;
        }
        int size = lists.length;
        return helper(lists, 0, size - 1);
    }
    private ListNode helper(ListNode[] lists, int start, int end) {
        if (start == end) {
            return lists[start];
        } else {
            int mid = (start + end) / 2;
            return merge2Lists(helper(lists, start, mid), helper(lists, mid + 1, end));
        }
    }
    private ListNode merge2Lists(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(0);
        ListNode prev = dummy;
        while (l1 != null && l2 != null) {
            if (l1.val <= l2.val) {
                prev.next = l1;
                l1 = l1.next;
            } else {
                prev.next = l2;
                l2 = l2.next;
            }
            prev = prev.next;
        }
        if (l1 != null) {
            prev.next = l1;
        }
        if (l2 != null) {
            prev.next = l2;
        }
        return dummy.next;
    }


    private boolean isAllNull(ListNode[] lists){
        for(ListNode node:lists){
            if(node!=null){
                return false;
            }
        }
        return true;
    }

    //AC,堆排0.2320，遍历0.0833，堆的使用是有效的
    public ListNode mergeKLists(ListNode[] lists) {
        ListNode pHead=new ListNode(0);
        ListNode pHeadBak=pHead;
        int minIndex=-1;
        int l=lists.length;
        int LIMIT=3;
        if(l>LIMIT) {
            //初始化堆
            for (int i = lists.length / 2 - 1; i >= 0; i--) {
                int j = i * 2 + 1;
                j = getJ(lists, j);
                if (lists[i]==null||(lists[j]!=null&&lists[j].val < lists[i].val)) {
                    ListNode tmp = lists[j];
                    lists[j] = lists[i];
                    lists[i] = tmp;
                    if(j<lists.length/2) {
                        i = j + 1;
                    }
                }
            }
        }
        while(!isAllNull(lists)){
            if(l>LIMIT) {
                //通过调整堆来找出最小的节点
                //2.调整堆
                boolean flag=true;
                int i=0;
                while(flag&&i<lists.length/2){
                    flag=false;
                    int j = i * 2 + 1;
                    j = getJ(lists, j);
                    if (lists[i]==null||(lists[j]!=null&&lists[j].val < lists[i].val)) {
                        ListNode tmp = lists[j];
                        lists[j] = lists[i];
                        lists[i] = tmp;
                        i=j;
                        flag=true;
                    }
                }
                //1.从堆顶取出当前最小节点
                pHead.next=lists[0];
                pHead=pHead.next;
                lists[0]=lists[0].next;
            }else{
                //遍历找出最小的节点
                for(int i=0;i<lists.length;i++){
                    ListNode node=lists[i];
                    if(node!=null){
                        if(minIndex==-1||lists[minIndex]==null){
                            minIndex=i;
                        }else{
                            if(node.val<lists[minIndex].val){
                                minIndex=i;
                            }
                        }
                    }
                }
                pHead.next=lists[minIndex];
                pHead=pHead.next;
                lists[minIndex]=lists[minIndex].next;
            }
        }
        return pHeadBak.next;
    }

    private int getJ(ListNode[] lists, int j) {
        if (j + 1 < lists.length ) {
            if( lists[j]==null) {
                j++;
            }else if(lists[j + 1]!=null&&lists[j + 1].val < lists[j].val){
                j++;
            }
        }
        return j;
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

        ListNode root31=new ListNode(0);
        ListNode root32=new ListNode(2);
        ListNode root33=new ListNode(5);
        root31.next=root32;
        root32.next=root33;

        wanxu_pursue_0023 instance=new wanxu_pursue_0023();
        instance.printList(root11);
        instance.printList(root21);
        instance.printList(root31);
//        instance.printList(instance.mergeKLists(new ListNode[]{null,root21}));
//        instance.printList(instance.mergeKLists(new ListNode[]{root11,null}));
//        instance.printList(instance.mergeKLists(new ListNode[]{null,root11,null,root21}));
        instance.printList(instance.mergeKLists(new ListNode[]{null,root11,null,null,root21,null,null,root31}));
        //[[],[-1,5,11],[],[6,10]]
    }
}
