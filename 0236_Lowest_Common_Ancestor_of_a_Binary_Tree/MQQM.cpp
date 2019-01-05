/*
  题目：
  给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
  
  做法：
  分别记录：找到所指定的两个节点时的节点序列。把问题转化为：两个数组找公共节点。
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
    bool findElement(TreeNode* root, TreeNode* e, vector<TreeNode*> &vec){
        //记录找到节点e时的节点序列(倒序：从节点e至root)
        if(root == NULL){
            return false;
        }
        if(root == e){
            vec.push_back(root);
            return true;
        }
        if( findElement(root->left, e, vec) || findElement(root->right, e, vec) ){
            vec.push_back(root);
            return true;                     
        } 
           
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> vec1, vec2;
        findElement(root, p, vec1);
        findElement(root, q, vec2);

        int len1 = vec1.size();
        int len2 = vec2.size();
        while(len1>0 && len2>0 && vec1[len1-1]==vec2[len2-1]){
            len1--;
            len2--;
        }
        
        return vec1[len1];
    }
};
