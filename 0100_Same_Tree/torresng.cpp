/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     ：Torres Ng
*   Create Time ：2018/11/19
*
***************************************************************/
/**************************************************************
Given two binary trees, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical and the nodes have the same value.

Example 1:

    Input:     1         1
              / \       / \
             2   3     2   3

            [1,2,3],   [1,2,3]

    Output: true

Example 2:

    Input:     1         1
              /           \
             2             2

            [1,2],     [1,null,2]

    Output: false

Example 3:

    Input:     1         1
              / \       / \
             2   1     1   2

            [1,2,1],   [1,1,2]

    Output: false
***************************************************************/
#include <iostream>
#include <vector>

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(p && q && p->val == q->val) 
            return isSameTree(p->left, q->left) &&
                isSameTree(p->right, q->right);
        return false;
    }
};

int main(void) {
    Solution s = Solution();
    // Example 1
    TreeNode *head1 = new TreeNode(1);
    TreeNode *node1 = new TreeNode(2);
    TreeNode *node2 = new TreeNode(3);
    head1->left = node1;
    head1->right = node2;
    TreeNode *head2 = new TreeNode(1);
    TreeNode *node3 = new TreeNode(2);
    TreeNode *node4 = new TreeNode(3);
    head2->left = node3;
    head2->right = node4;
    cout << "[1,2,3],  [1,2,3]: " << boolalpha << s.isSameTree(head1, head2) << endl;

    // Example 2
    head1->val = 1;
    node1->val = 2;
    head1->left = node1;
    head1->right = NULL;
    head2->val = 1;
    node4->val = 2;
    head2->left = NULL;
    head2->right = node4;
    cout << "[1,2],  [1,null,2]: " << boolalpha << s.isSameTree(head1, head2) << endl;

    // Example 2
    head1->val = 1;
    node1->val = 2;
    node2->val = 1;
    head1->left = node1;
    head1->right = node2;
    head2->val = 1;
    node3->val = 1;
    node4->val = 2;
    head2->left = node3;
    head2->right = node4;
    cout << "[1,2,1],  [1,1,2]: " << boolalpha << s.isSameTree(head1, head2) << endl;
    return 0;
}


