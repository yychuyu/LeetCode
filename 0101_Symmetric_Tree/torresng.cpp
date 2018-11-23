/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     ：Torres Ng
*   Create Time ：2018/11/19
*
***************************************************************/
/**************************************************************
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

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
#include <iostream>
#include <deque>

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
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        deque<TreeNode*> d;
        TreeNode *preNode, *postNode;
        d.push_front(root->left);
        d.push_back(root->right);
        while(d.size()) {
            preNode = d.front(); 
            postNode = d.back();
            d.pop_front();
            d.pop_back();
            if(!preNode && !postNode) continue;
            if(!preNode || !postNode) return false;
            if(preNode->val != postNode->val)  {
                return false;
            } else {
                d.push_front(preNode->right);
                d.push_back(postNode->left);
                d.push_front(preNode->left);
                d.push_back(postNode->right);
            }
        }
        return true;
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
    node1->left = NULL;
    node1->right = node3;
    node2->left = NULL;
    node2->right = node4;
    node3->left = NULL;
    node3->right = NULL;
    node4->left = NULL;
    node4->right = NULL;
    cout << "[1,2,2,null,3,null,3]: " << boolalpha << s.isSymmetric(head) << endl;

    // Example 3
    head->val = 1;
    node1->val = 2;
    node2->val = 3;
    node3->val = 3;
    node4->val = 2;
    head->left = node1;
    head->right = node2;
    node1->left = node3;
    node1->right = NULL;
    node2->left = node4;
    node2->right = NULL;
    node3->left = NULL;
    node3->right = NULL;
    node4->left = NULL;
    node4->right = NULL;
    cout << "[1,2,2,null,3,null,3]: " << boolalpha << s.isSymmetric(head) << endl;

    return 0;
}



