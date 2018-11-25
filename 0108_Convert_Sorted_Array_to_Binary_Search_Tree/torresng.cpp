/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     ：Torres Ng
*   Create Time ：2018/11/24
*
***************************************************************/
/**************************************************************
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

    Given the sorted array: [-10,-3,0,5,9],

    One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

          0
         / \
       -3   9
       /   /
     -10  5
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        size_t len = nums.size();
        if(len == 0) return NULL;
        size_t mid = len/2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = ToBST(nums, 0, mid);
        root->right = ToBST(nums, mid+1, len);
        return root;
    }
private:
    TreeNode* ToBST(vector<int>& nums, size_t start, size_t end) {
        if(start >= end) return NULL;
        size_t mid = (start+end)/2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = ToBST(nums, start, mid);
        node->right = ToBST(nums, mid+1, end);
        return node;
    }
};


void print(TreeNode* root) {
    queue<TreeNode*> q;
    if(root == nullptr) return;
    q.push(root);
    cout << "[";
    while(!q.empty()) {
        TreeNode *p = q.front();
        q.pop();
        if(p != nullptr) {
            q.push(p->left);
            q.push(p->right);
        }
        string val;
        if(p == nullptr) {
            val = "null";
        } else {
            val = to_string(p->val);
        }
        cout << val;
        if(!q.empty()) cout << ",";
    }
    cout << "]" << endl;
}

int main(void) {
    Solution s = Solution();
    // Example 1
    vector<int> nums {-10,-3,0,5,9};
    cout << "[-10,-3,0,5,9]: " << endl;
    TreeNode *root = s.sortedArrayToBST(nums);
    print(root);

    return 0;
}

