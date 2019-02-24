/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//克隆根节点，镜像遍历比较
bool traverse(struct TreeNode* p, struct TreeNode* q) {
    if (p == q && p == NULL) {
        return true;
    }
    if ((p == NULL && q != NULL) || 
        (q == NULL && p != NULL) || 
        (p != NULL && q != NULL && p->val != q->val)) {
        return false;
    }
    return traverse(p->left, q->right) && traverse(p->right, q->left);
}

bool isSymmetric(struct TreeNode* root) {
    return traverse(root, root);
}
