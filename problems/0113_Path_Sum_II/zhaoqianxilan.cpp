#include<iostream>
#include<vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 由二维数组生成二叉树
struct TreeNode *createTreeFromArray(int *nums, int numsSize) {
	const int numMeansNull = 0;
	struct TreeNode *nodes = (struct TreeNode*)calloc(numsSize, sizeof(struct TreeNode));
	for (int i = 0; i < numsSize; i++) {
		nodes[i].val = nums[i];
		int child = i * 2 + 1;
		nodes[i].left = (child < numsSize && nums[child] != numMeansNull) ? &nodes[child] : NULL;
		child = i * 2 + 2;
		nodes[i].right = (child < numsSize && nums[child] != numMeansNull) ? &nodes[child] : NULL;
	}
	return &nodes[0];
}

class Solution {
private:
	vector<vector<int>> res;
	vector<int> path;
	int currentSum = 0;
	int targetSum = 0;
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		targetSum = sum;
		dfs(root);
		return res;
	}

private:
	void dfs(TreeNode *t) {
		if (t == NULL) {
			return;
		}
			
		currentSum += t->val;
		path.push_back(t->val);

		if (currentSum == targetSum && !t->left && !t->right) {
			res.push_back(path);
		}
		else {
			dfs(t->left);
			dfs(t->right);
		}
		path.pop_back();
		currentSum -= t->val;
	}
};

int main() {
	//int nums[] = { 5,4,8,11,0,13,4,7,2,0,0,0,0,5,1 };
	int nums[] = { 1 };
	struct TreeNode* root = createTreeFromArray(nums, 1);
	Solution s;
	vector<vector<int>> res = s.pathSum(root, 1);
	return 0;
}