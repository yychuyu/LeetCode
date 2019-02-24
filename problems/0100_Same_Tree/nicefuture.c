/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == q && p == NULL) {
        return true;
    }
    if ((p == NULL && q != NULL) || 
        (q == NULL && p != NULL) || 
        (p != NULL && q != NULL && p->val != q->val)) {
        return false;
    }
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
