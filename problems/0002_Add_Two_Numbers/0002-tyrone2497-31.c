/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *l = NULL , *l_temp = NULL, *l1_temp = l1, *l2_temp = l2;
    int carry_bit = 0;
    
    /* 头结点申请 */
    l = (struct ListNode *)malloc(sizeof(struct ListNode));
    if (!l)
        return NULL;
    memset(l, 0, sizeof(struct ListNode));

    l_temp = l;
    while (l1_temp || l2_temp || carry_bit) {
        /* 进行加法运算 */
        if (l1_temp && l2_temp) {
            l_temp->val = l1_temp->val + l2_temp->val + carry_bit;
            l1_temp = l1_temp->next;
            l2_temp = l2_temp->next;
        } else if (l1_temp) {
            l_temp->val = l1_temp->val + carry_bit;
            l1_temp = l1_temp->next;
        } else if (l2_temp) {
            l_temp->val = l2_temp->val + carry_bit;
            l2_temp = l2_temp->next;
        } else
            l_temp->val = carry_bit;
        
        /* 判断是否有进位 */
        if (l_temp->val >= 10) {
            l_temp->val -= 10;
            carry_bit = 1;
        } else
            carry_bit = 0;
        
        /* 申请后续节点 */
        if (l1_temp || l2_temp || carry_bit) {
            l_temp->next = (struct ListNode *)malloc(sizeof(struct ListNode));
            l_temp = l_temp->next;
            if (!l_temp)
                break;
            memset(l_temp, 0, sizeof(struct ListNode));
        }
    }
    
    return l;
}
