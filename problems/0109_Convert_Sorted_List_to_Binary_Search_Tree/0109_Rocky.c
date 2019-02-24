/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* generateTree(int *list, int start, int end) {
    if (start >= end) return NULL;
    
    struct TreeNode *tree = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    int mid;
    mid = start + (end - start) / 2; 
    tree->val = list[mid];
    tree->left = generateTree(list, start, mid);
    tree->right = generateTree(list, mid + 1, end);

    return tree;
}

struct TreeNode* sortedListToBST(struct ListNode* head) {
    int list[100000];
    int len = 0;
    
    while (head != NULL) {
        list[len] = head->val;
        head = head->next;
        len++;
    }
    
    return generateTree(list, 0, len);
}
