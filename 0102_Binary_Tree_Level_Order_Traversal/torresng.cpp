/***************************************************************
 *   Copyright (C) 2018 All rights reserved.
 *
 *   Auth     ：Torres Ng
 *   Create Time ：2018/10/24
 *
 ***************************************************************/
/**************************************************************
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],

        3
       / \
      9  20
        /  \
       15   7

return its level order traversal as:

    [
      [3],
      [9,20],
      [15,7]
    ]
 ***************************************************************/

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

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
        vector<vector<int>> levelOrder(TreeNode* root) {
            if(root == nullptr) return {};
            vector<vector<int>> result;
            queue<pair<TreeNode*, int>> q;
            pair<TreeNode*, int> p;
            TreeNode *node;
            int level;
            q.push(make_pair(root, 1));
            while(!q.empty()) {
                p = q.front();
                node = p.first;
                level = p.second;
                if(level > result.size()) {
                    result.push_back({node->val});
                } else {
                    result[level-1].push_back(node->val);
                }
                if(node->left) q.push(make_pair(node->left, level+1));
                if(node->right) q.push(make_pair(node->right, level+1));
                q.pop();
            }
            return result;
        }
};

string join(const vector<int>& v, string c) {
    string s;
    for (vector<int>::const_iterator p = v.begin();
            p != v.end(); ++p) {
        s += to_string(*p);
        if (p != v.end() - 1)
            s += c;
    }
    return "[" + s + "]";
}

void print(vector<vector<int>> v) {
    cout << "[" << endl;
    for(auto i : v) {
        cout << join(i, ",") << endl;
    }
    cout << "]" << endl;
}

int main(void) {
    Solution s = Solution();
    TreeNode *head = new TreeNode(3);
    TreeNode *node1 = new TreeNode(9);
    TreeNode *node2 = new TreeNode(20);
    TreeNode *node3 = new TreeNode(15);
    TreeNode *node4 = new TreeNode(7);
    head->left = node1;
    head->right = node2;
    node2->left = node3;
    node2->right = node4;

    cout << "[3,9,20,null,null,15,7]: " << endl;
    vector<vector<int>> result = s.levelOrder(head);
    print(result);
    return 0;
}
