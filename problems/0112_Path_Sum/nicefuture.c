/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool find = false;
void tranverse(struct TreeNode* p, int *result, int sum) {
    if (find || p == NULL) return;
    *result += p->val;
    if (p->left == NULL && p->right == NULL) {
        find = (*result == sum);
        *result -= p->val;
        return;
    }
    tranverse(p->left, result, sum);
    tranverse(p->right, result, sum);
    *result -= p->val;
}
bool hasPathSum(struct TreeNode* root, int sum) {
    find = false;
    int result = 0;
    tranverse(root, &result, sum);
    return find;
}
