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
        queue<struct TreeNode*> q;
        vector<vector<int>> arr_out;
        vector<int> arr_in;
        
        if (root == NULL) return arr_out;
        
        q.push(root);
        q.push(NULL);
        while (!q.empty()) {
            struct TreeNode *p = q.front();
            q.pop();
            if (p != NULL) {
                arr_in.push_back(p->val);
                if (p->left != NULL) q.push(p->left);
                if (p->right != NULL) q.push(p->right);
            } else {
                arr_out.insert(arr_out.begin(), arr_in);
                arr_in.clear();
                if(!q.empty()) q.push(NULL);
            }
        }
        // reverse(arr_out.begin(), arr_out.end());
        return arr_out;
    }
};
