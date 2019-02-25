// recursion version
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> data;
        preorder(root,data);
        return data;
    }
    void preorder(TreeNode* root,vector<int>& data){
        if(root == nullptr)
            return;
        data.push_back(root->val);
        preorder(root->left,data);
        preorder(root->right,data);
    }
};
// non-recursion version
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> data;
        stack<TreeNode*> S;
        while(true){
            while(root != nullptr){
                S.push(root);
                data.push_back(root->val);
                root = root->left;
            }
            if(S.empty())
                break;
            else{
                root = S.top()->right;
                S.pop();
            }
        }
        return data;
    }
};
