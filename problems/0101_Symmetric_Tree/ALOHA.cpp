class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if( root == NULL ){
            return true;
        }
        
        return isEqual(root->left, root->right);            
    }
    bool isEqual(TreeNode* left, TreeNode* right){
        if( left == NULL && right == NULL ){
            return true;
        }
        if( left == NULL || right == NULL ){
            return false;
        }
        if( left->val != right->val ){
            return false;
        }
        
        return isEqual(left->left, right->right) && isEqual(left->right, right->left);       
    }
};