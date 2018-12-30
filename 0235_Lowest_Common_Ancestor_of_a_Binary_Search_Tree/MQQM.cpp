/*
  题目：
  给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL;
        }
        
        if( p->val > root->val && q->val > root->val ){//两个都在右子树
            return lowestCommonAncestor(root->right, p, q);
        }else if( p->val < root->val && q->val < root->val ){//两个都在左子树
            return lowestCommonAncestor(root->left, p, q);
        }
        //一个在左，一个在右
        return root;
    }
};
