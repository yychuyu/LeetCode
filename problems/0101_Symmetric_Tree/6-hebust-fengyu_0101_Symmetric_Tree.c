/*
 * @lc app=leetcode.cn id=101 lang=c
 *
 * [101] 对称二叉树
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool getResult(struct TreeNode *l, struct TreeNode *r){
    if(l != NULL && r != NULL) return l->val == r->val && getResult(l->left, r->right) && getResult(l->right, r->left);
    else if(l == NULL && r == NULL) return true;
    else return false;
}

bool isSymmetric(struct TreeNode* root){
    if(root == NULL) return true;
    else if(root->left == NULL && root->right == NULL) return true;
    else return getResult(root->left, root->right);
}



