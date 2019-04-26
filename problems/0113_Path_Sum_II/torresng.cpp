/***************************************************************
 *
 *   Auth     ：Torres Ng
 *   Create Time ：2019/04/26
 *
 ***************************************************************/
/**************************************************************
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum
equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1

Return:

[
   [5,4,11,2],
   [5,8,4,5]
]
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
    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        if (root == nullptr)
            return res;
        dfs(root, sum, path, res);
        return res;
    }

    void dfs(TreeNode *root, int sum, vector<int> &path,
             vector<vector<int>> &res) {
        if (root == nullptr)
            return;
        path.push_back(root->val);
        sum -= root->val;
        if (root->left == nullptr && root->right == nullptr && sum == 0) {
            res.push_back(path);
        } else {
            dfs(root->left, sum, path, res);
            dfs(root->right, sum, path, res);
        }
        path.pop_back();
        return;
    }
};

bool compare(vector<vector<int>> v1, vector<vector<int>> v2) {
    if (v1.size() != v2.size()) {
        return false;
    }
    for (unsigned long i = 0; i < v1.size(); ++i) {
        if (v1[i].size() != v2[i].size()) {
            return false;
        }
        unsigned long size = v1[i].size();
        for (unsigned long j = 0; j < size; ++j) {
            if (v1[i][j] != v2[i][j]) {
                return false;
            }
        }
    }

    return true;
}

void test_case_1() {
    TreeNode head(5);
    TreeNode p1(4);
    TreeNode p2(8);
    TreeNode p3(11);
    TreeNode p4(13);
    TreeNode p5(4);
    TreeNode p6(7);
    TreeNode p7(2);
    TreeNode p8(5);
    TreeNode p9(1);
    head.left = &p1;
    head.right = &p2;
    p1.left = &p3;
    p2.left = &p4;
    p2.right = &p5;
    p3.left = &p6;
    p3.right = &p7;
    p5.left = &p8;
    p5.right = &p9;

    vector<vector<int>> ans = {{5, 4, 11, 2}, {5, 8, 4, 5}};
    vector<vector<int>> res = Solution().pathSum(&head, 22);

    assert(compare(res, ans) == true);
}

void test_case_2() {
    vector<vector<int>> ans = {};
    vector<vector<int>> res = Solution().pathSum(nullptr, 1);

    assert(compare(res, ans) == true);
}

int main(void) {
    test_case_1();
    test_case_2();

    return 0;
}
