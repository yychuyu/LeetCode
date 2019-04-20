#include<stdio.h>
#include<malloc.h>
/**
* Definition for a binary tree node.*/
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

	TreeNode(int x) {
		val = x;
		left = NULL;
		right = NULL;
	}
};

// 迭代方式，利用栈结构对两个树进行遍历
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
	struct TreeNode *stack_p[4096] ;
	int size_p = 0;
	struct TreeNode *stack_q[4096];
	int size_q = 0;
	int i = 0;
	if (p && q){
		stack_p[size_p] = p;
		size_p++;
		stack_q[size_q] = q;
		size_q++;
	}
	else if (p == NULL  & q == NULL)
		return true;
	else
		return false;

	while (size_p){
		// 判断当前出栈节点数据是否相同
		size_p--;
		size_q--;
		p = stack_p[size_p];
		q = stack_q[size_q];
		if (p->val != q->val){
			return false;
		}

		//判断非空，然后入栈
		// 右孩子先入栈
		if (p->right && q->right){
			stack_p[size_p] = p->right;
			size_p++;
			stack_q[size_q] = q->right;
			size_q++;
		}
		else if (p->right == NULL && q->right == NULL);
		else return false;

		// 左孩子入栈
		if (p->left && q->left){
			stack_p[size_p] = p->left;
			size_p++;
			stack_q[size_q] = q->left;
			size_q++;
		}
		else if (p->left == NULL && q->left == NULL);
		else return false;
	}
	return true;
}

// 递归 原文：https ://blog.csdn.net/xishirujin_/article/details/51235733 
bool isSameTree1(struct TreeNode* p, struct TreeNode* q) {
	if (p == NULL&&q == NULL)
		return true;
	if (p == NULL || q == NULL)
		return false;
	return p->val == q->val&&isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

}

int main(){
	TreeNode t1(1), t2(2), t3(3);
	t1.left = &t2;
	t1.right = &t3;
	TreeNode y1(1), y2(2), y3(3);
	y1.left = &y2;
	y1.right = &y3;

	isSameTree(&t1, &y1);
	return 0;
}
