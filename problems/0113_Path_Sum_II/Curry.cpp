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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;
        vector<int> cur;
        dfs(root, sum, cur, ans);

        return ans;
    }
    
private:
    void dfs(TreeNode *root, int sum, vector<int> cur, vector<vector<int>> &ans) {
        if (root == nullptr) return;
        if (root->left == nullptr && root->right == nullptr && sum == root->val) {
            cur.push_back(root->val);
            ans.push_back(cur);
            return;
        }
        
        cur.push_back(root->val);
        dfs(root->left, sum - root->val, cur, ans);
        dfs(root->right, sum - root->val, cur, ans);
    }
};
