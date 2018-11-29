/***************************************************************
*
*   Auth     ：Torres Ng
*   Create Time ：2018/11/29
*
***************************************************************/
/**************************************************************
Given two binary trees and imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not.

You need to merge them into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of new tree.

Example 1:

    Input: 
        Tree 1                     Tree 2                  
              1                         2                             
             / \                       / \
            3   2                     1   3                        
           /                           \   \
          5                             4   7                  
    Output: 
    Merged tree:
             3
            / \
           4   5
          / \   \
         5   4   7
***************************************************************/
#include <iostream>
#include <vector>
#include <queue>
#include <string>

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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1 == nullptr && t2 == nullptr) return nullptr;
        if(t1 == nullptr) return t2;
        if(t2 == nullptr) return t1;
        t1->val += t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        return t1;
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
    TreeNode *head1 = new TreeNode(1);
    TreeNode *node1 = new TreeNode(3);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(5);
    head1->left = node1;
    head1->right = node2;
    node1->left = node3;

    TreeNode *head2 = new TreeNode(2);
    TreeNode *node4 = new TreeNode(1);
    TreeNode *node5 = new TreeNode(3);
    TreeNode *node6 = new TreeNode(4);
    TreeNode *node7 = new TreeNode(7);
    head2->left = node4;
    head2->right = node5;
    node4->right = node6;
    node5->right = node7;

    cout << "Tree 1 : [1,3,2,5,NULL,NULL,NULL,NULL]" << endl;
    cout << "Tree 2 : [2,1,3,NULL,4,NULL,7]" << endl;
    cout << "Result :";

    TreeNode *res = s.mergeTrees(head1, head2);
    print(res);

    return 0;
}


