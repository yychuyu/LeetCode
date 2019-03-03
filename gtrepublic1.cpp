//leetcode 101
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr)
            return true;
        return isEqual(root->left, root->right);
    }
    bool isEqual(TreeNode* p, TreeNode* q){
        if(p == nullptr && q == nullptr)
            return true;
        if((p == nullptr && q != nullptr) ||(p != nullptr && q == nullptr))
            return false;
        else return (p->val == q->val && isEqual(p->left, q->right) && isEqual(p->right, q->left));
        
    }
};This file is added by republic
This file is added by republic
