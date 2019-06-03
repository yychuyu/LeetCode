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
    vector<TreeNode*> res;
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        dfs(root);
        int len = res.size();
        res[0]->left = NULL;
        for (int i = 0; i < len - 1; i++) {
            res[i]->right = res[i+1];
            res[i+1]->left = NULL;
        }
    }
    void dfs(TreeNode* root) {
        if (!root) return;
        else {
            res.push_back(root);
            dfs(root->left);
            dfs(root->right);
        }
        return;
    }
};
