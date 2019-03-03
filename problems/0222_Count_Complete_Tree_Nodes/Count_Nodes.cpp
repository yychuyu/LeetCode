/*
  题目：
  给出一个完全二叉树，求出该树的节点个数。
*/

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
    int countNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        
        int leftDepth=1,rightDepth=1;
        TreeNode* p=NULL;
        p=root->left;
        while(p!=NULL){
            leftDepth++;
            p=p->left;
        }
        p=root->right;
        while(p!=NULL){
            rightDepth++;
            p=p->right;
        }
        
        if(leftDepth==rightDepth){
            return (1<<leftDepth)-1;
        }else{
            return countNodes(root->left)+countNodes(root->right)+1;
        }
    
    }
};
