#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;
// Definition for a binary tree node.
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

/*
三种情况：
1、左右都为空
2、左右一个有一个没有
3、左右有不对称
*/
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if( root == NULL ){
            return true;
        }
        
        return isEqual(root->left, root->right);            
    }
    bool isEqual(TreeNode* left, TreeNode* right)
    {//给定的两个节点已经是对应位置上的节点
        if( left == NULL && right == NULL )
        {//两个节点都是空
            return true;
        }
        if( left == NULL || right == NULL )
        {//有一个节点是空
            return false;
        }
        if( left->val != right->val )
        {//两个节点都存在，但是不相同
            return false;
        }
        
        return isEqual(left->left, right->right) && isEqual(left->right, right->left);       
    }
};
int main()
{
    Solution method;
    TreeNode *root;
    
    bool result = method.isSymmetric(root);
    return 0;
}
