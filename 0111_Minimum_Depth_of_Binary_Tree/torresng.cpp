/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     ：Torres Ng
*   Create Time ：2018/11/25
*
***************************************************************/
/**************************************************************
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

        3
       / \
      9  20
        /  \
       15   7

return its minimum depth = 2.
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
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        if(root->left && !root->right) return minDepth(root->left) + 1;
        if(!root->left && root->right) return minDepth(root->right) + 1;
        return min(minDepth(root->left), minDepth(root->right)) + 1;
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
    cout << "[3,9,20,null,null,15,7]: " << boolalpha << s.minDepth(head) << endl;

    // Example 2
    head->val = 1;
    node1->val = 2;
    head->left = node1;
    head->right = nullptr;
    cout << "[1,2]: " << boolalpha << s.minDepth(head) << endl;

    return 0;
}
