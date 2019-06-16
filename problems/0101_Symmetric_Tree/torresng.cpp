/***************************************************************
 *   Copyright (C) 2018 All rights reserved.
 *
 *   Auth     ：Torres Ng
 *   Create Time ：2018/11/19
 *
 ***************************************************************/
/**************************************************************
Given a binary tree, check whether it is a mirror of itself (ie, symmetric
around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

        1
       / \
      2   2
     / \ / \
    3  4 4  3

But the following [1,2,2,null,3,null,3] is not:

        1
       / \
      2   2
       \   \
       3    3

Note:
Bonus points if you could solve it both recursively and iteratively.
***************************************************************/

/*
 *http://blog.torresng.com/2018/11/23/LeetCode-No-101-Submission-Detail/
 */

#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
  public:
    bool isSymmetric(TreeNode *root) {
        if (!root)
            return true;
        return compare(root->left, root->right);
    }

  private:
    bool compare(TreeNode *p1, TreeNode *p2) {
        if (!p1 && !p2)
            return true;
        if (!p1 || !p2)
            return false;
        if (p1->val != p2->val)
            return false;
        return compare(p1->left, p2->right) && compare(p1->right, p2->left);
    }
};

int main(void) {
    Solution s = Solution();
    // Example 1
    TreeNode *head = new TreeNode(1);
    TreeNode *node1 = new TreeNode(2);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node5 = new TreeNode(4);
    TreeNode *node6 = new TreeNode(3);
    head->left = node1;
    head->right = node2;
    node1->left = node3;
    node1->right = node4;
    node2->left = node5;
    node2->right = node6;
    cout << "[1,2,2,3,4,4,3]: " << boolalpha << s.isSymmetric(head) << endl;

    // Example 2
    head->val = 1;
    node1->val = 2;
    node2->val = 2;
    node3->val = 3;
    node4->val = 3;
    head->left = node1;
    head->right = node2;
    node1->left = nullptr;
    node1->right = node3;
    node2->left = nullptr;
    node2->right = node4;
    node3->left = nullptr;
    node3->right = nullptr;
    node4->left = nullptr;
    node4->right = nullptr;
    cout << "[1,2,2,null,3,null,3]: " << boolalpha << s.isSymmetric(head)
         << endl;

    // Example 3
    head->val = 1;
    node1->val = 2;
    node2->val = 3;
    node3->val = 3;
    node4->val = 2;
    head->left = node1;
    head->right = node2;
    node1->left = node3;
    node1->right = nullptr;
    node2->left = node4;
    node2->right = nullptr;
    node3->left = nullptr;
    node3->right = nullptr;
    node4->left = nullptr;
    node4->right = nullptr;
    cout << "[1,2,2,null,3,null,3]: " << boolalpha << s.isSymmetric(head)
         << endl;

    return 0;
}
