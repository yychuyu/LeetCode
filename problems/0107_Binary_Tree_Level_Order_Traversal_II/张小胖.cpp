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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
         vector<vector<int>> array;
        levelorder(root, 0,array);
        return vector<vector<int>> (array.rbegin(), array.rend());
    }
    void levelorder(TreeNode *root, int level, vector<vector<int> > &array) {
        if (root==nullptr) return;
        if (array.size() == level) array.push_back({});
        array[level].push_back(root->val);
        if (root->left) levelorder(root->left, level + 1, array);
        if (root->right) levelorder(root->right, level + 1, array);
    }
};
