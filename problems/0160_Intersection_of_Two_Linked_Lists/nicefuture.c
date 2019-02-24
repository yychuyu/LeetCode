/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int getLength(struct ListNode *head) {
    int len = 0;
    struct ListNode *p = head;
    while (p != NULL) {
        len++;
        p = p->next;
    }
    return len;
}
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *p = headA, *q = headB;
    
    /*//暴力法
    while (p != NULL) {
        q = headB;
        while (q != NULL) {
            if (p == q) return p;
            q = q->next;
        }
        p = p->next;
    }
    return NULL;
    */
    
    //分别求长度
    int lenA = getLength(headA), lenB = getLength(headB);
    //移动指针
    if (lenA >= lenB) {  //如果 listA 更长
        int sub = lenA-lenB;
        while (sub > 0) {  //则 A 上指针前移两者长度之差个节点
            p = p->next;
            sub--;
        }
    } else {
        int sub = lenB-lenA;
        while (sub > 0) {
            q = q->next;
            sub--;
        }
    }
    //之后两指针将同时到达交叉点
    while (p != NULL && q != NULL) {
        if (p == q) return p;
        p = p->next;
        q = q->next;
    }
    return NULL;
}
