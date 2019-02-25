/*
  题目：
  给定一个二叉搜索树，编写一个函数 kthSmallest 来查找其中第 k 个最小的元素。
  
  说明：
  你可以假设 k 总是有效的，1 ≤ k ≤ 二叉搜索树元素个数。
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
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL){
            return 0;
        }
        
        kthSmallest(root->left, k);
        vec.push_back(root->val);
        kthSmallest(root->right, k);
        
        return vec[k-1];
    }
private:
    vector<int> vec;    
};
