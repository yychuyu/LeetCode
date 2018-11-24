/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     ：Torres Ng
*   Create Time ：2018/11/25
*
***************************************************************/
/**************************************************************
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

    a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example 1:

Given the following tree [3,9,20,null,null,15,7]:

        3
       / \
      9  20
        /  \
       15   7

Return true.

Example 2:

Given the following tree [1,2,2,3,3,null,null,4,4]:

           1
          / \
         2   2
        / \
       3   3
      / \
     4   4

Return false.
***************************************************************/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        int ldepth = depth(root->left);
        int rdepth = depth(root->right);
        if(abs(ldepth - rdepth) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
private:
    int depth(TreeNode* p) {
        if(p == nullptr) return 0;
        return max(depth(p->left), depth(p->right)) + 1;
    }
};

int main(void) {
    Solution s = Solution();
    // Example 1
    TreeNode *head = new TreeNode(3);
    TreeNode *node1 = new TreeNode(9);
    TreeNode *node2 = new TreeNode(20);
    TreeNode *node3 = new TreeNode(15);
    TreeNode *node4 = new TreeNode(7);
    head->left = node1;
    head->right = node2;
    node2->left = node3;
    node2->right = node4;
    cout << "[3,9,20,null,null,15,7]: " << boolalpha << s.isBalanced(head) << endl;

    // Example 2
    head->val = 1;
    node1->val = 2;
    node2->val = 2;
    node3->val = 3;
    node4->val = 3;
    TreeNode *node5 = new TreeNode(4);
    TreeNode *node6 = new TreeNode(4);
    head->left = node1;
    head->right = node2;
    node1->left = node3;
    node1->right = node4;
    node2->left = nullptr;
    node2->right = nullptr;
    node3->left = node5;
    node3->right = node5;
    node4->left = nullptr;
    node4->right = nullptr;
    cout << "[1,2,2,3,3,null,null,4,4]: " << boolalpha << s.isBalanced(head) << endl;
    
    // Example 3
    head->val = 1;
    node1->val = 2;
    node2->val = 2;
    node3->val = 3;
    node4->val = 3;
    node5->val = 4;
    node6->val = 4;
    head->left = node1;
    head->right = node2;
    node1->left = node3;
    node2->right = node4;
    node3->left = node5;
    node4->right = node6;
    cout << "[1,2,2,3,null,null,3,4,null,null,4]: " << boolalpha << s.isBalanced(head) << endl;

    return 0;
}
