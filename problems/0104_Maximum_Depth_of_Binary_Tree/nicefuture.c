/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int depth = 0;

void traverse(struct TreeNode* p, int level) {
    if (p == NULL) return;
    if (level > depth) depth = level;
    traverse(p->left, level+1);
    traverse(p->right, level+1);
}

int maxDepth(struct TreeNode* root) {
    depth = 0;
    traverse(root, 1);
    return depth;
}


