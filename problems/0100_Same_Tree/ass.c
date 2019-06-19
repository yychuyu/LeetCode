/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//递归递归是真的强，要来一种非递归的才好
//BFS应该可以实现但不免要麻烦一点
bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if(p == NULL &&q==NULL){
     return true;
    }
    if(p!=NULL&&q!=NULL&&p->val==q->val){
        return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
    }
    else{
    return false;
    }
}

