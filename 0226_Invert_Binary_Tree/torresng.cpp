/***************************************************************
*
*   Auth     ：Torres Ng
*   Create Time ：2018/11/29
*
***************************************************************/
/**************************************************************
Invert a binary tree.

Example:

Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9

Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1

Trivia:
This problem was inspired by this original tweet by Max Howell:

    Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so f*** off.
***************************************************************/
#include <iostream>
#include <string>
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
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode *p = q.front();
            q.pop();
            swap(p->left, p->right);
            if(p->left) q.push(p->left);
            if(p->right) q.push(p->right);
        }
        return root;
    }
};

template<class T>
string join(const vector<T>& v, string c) {
    string s;
    for (typename vector<T>::const_iterator p = v.begin();
            p != v.end(); ++p) {
        s += to_string(*p);
        if (p != v.end() - 1)
            s += c;
    }
    return "[" + s + "]";
}

template<>
string join(const vector<string> &v, string c) {
    string s;
    for (vector<string>::const_iterator p = v.begin();
            p != v.end(); ++p) {
        s += *p;
        if (p != v.end() - 1)
            s += c;
    }
    return "[" + s + "]";
}

void print(TreeNode *root) {
    if(root == nullptr) return;
    vector<string> vec;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode *p = q.front();
        q.pop();
        if(p == nullptr) {
            vec.push_back("NULL");
        } else {
            q.push(p->left);
            q.push(p->right);
            vec.push_back(to_string(p->val));
        }
    }
    cout << join(vec, ",") << endl;
}

int main(void) {
    Solution s = Solution();
    // Example 1
    TreeNode *head = new TreeNode(4);
    TreeNode *node1 = new TreeNode(2);
    TreeNode *node2 = new TreeNode(7);
    TreeNode *node3 = new TreeNode(1);
    TreeNode *node4 = new TreeNode(3);
    TreeNode *node5 = new TreeNode(6);
    TreeNode *node6 = new TreeNode(9);
    head->left = node1;
    head->right = node2;
    node1->left = node3;
    node1->right = node4;
    node2->left = node5;
    node2->right = node6;

    cout << "Input: [4,2,7,1,3,6,8]" << endl;
    cout << "Output: ";
    print(s.invertTree(head));

    return 0;
}

