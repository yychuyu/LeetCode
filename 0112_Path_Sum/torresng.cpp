/***************************************************************
*
*   Auth     ：Torres Ng
*   Create Time ：2018/11/25
*
***************************************************************/
/**************************************************************
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

          5
         / \
        4   8
       /   / \
      11  13  4
     /  \      \
    7    2      1

return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == nullptr) return false;
        sum -= root->val;
        if(root->left == nullptr 
            && root->right == nullptr && sum == 0) return true;
        if(hasPathSum(root->left, sum)) return true;
        if(hasPathSum(root->right, sum)) return true;
        return false;
    }
};

int main(void) {
    Solution s = Solution();
    // Example 1
    TreeNode *head = new TreeNode(5);
    TreeNode *node1 = new TreeNode(4);
    TreeNode *node2 = new TreeNode(8);
    TreeNode *node3 = new TreeNode(11);
    TreeNode *node4 = new TreeNode(13);
    TreeNode *node5 = new TreeNode(4);
    TreeNode *node6 = new TreeNode(7);
    TreeNode *node7 = new TreeNode(2);
    TreeNode *node8 = new TreeNode(1);
    head->left = node1;
    head->right = node2;
    node1->left = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node3->right = node7;
    node5->right = node8;
    int sum = 22;
    cout << "[5,4,8,11,null,13,4,7,2,nul,null,null,1] sum = 22: " << boolalpha << s.hasPathSum(head, sum) << endl;

    head->val = 1;
    node1->val = 2;
    head->left = node1;
    head->right = nullptr;
    sum = 1;
    cout << "[1,2] sum = 1: " << boolalpha << s.hasPathSum(head, sum) << endl;

    return 0;
}

