class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL||(root->left==NULL&&root->right==NULL)) return root;
        TreeNode *temp=root->left;
        root->left=invertTree(root->right);
        root->right=invertTree(temp);
        return root;
    }
};