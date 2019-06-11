/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *    int val;
 *    struct TreeNode *left;
 *    struct TreeNode *right;
 *};
 **/


//要求二叉树展开为链表，即先前序遍历二叉树，右子树为下一个节点，左子树为空


/********************************************************************************************************************
 * 思路一：前序第归遍历树，将所有经过的节点都存入栈，弹栈从尾到头连接
 * 	（理解简单，但消耗内存过大,且没有释放栈，不是最好的方法）
 * TC: O(n)   SC: O(n)+O(n)
 * Runtime: 16 ms, faster than 22.09% of C online submissions
 * Memory Usage: 19.3 MB, less than 5.13% of C online submissions
 * ******************************************************************************************************************/

void Recursively_traversal(struct TreeNode *root, struct TreeNode ***stack, int *top){
	if( root )
	{
		*stack = (struct TreeNode **) realloc(*stack, sizeof(struct TreeNode*) * (++(*top)));		//扩大栈，并将遍历节点入栈	
		(*stack)[*top-1] = root;
		Recursively_traversal(root->left, stack, top);
		Recursively_traversal(root->right, stack, top);
	}
}

void flatten(struct TreeNode* root){
	if( !root || (!root->right && !root->left) )	return;
	struct TreeNode **stack = (struct TreeNode **) malloc(sizeof(struct TreeNode*));
	int top = 0;
	Recursively_traversal(root, &stack, &top);				//函数结束后，stack内存了所有节点，此时top指向栈顶
	struct TreeNode *cur, *pre;
	cur = stack[--top];
	while( 0 != top )							//弹栈，并从后往前连接节点
	{
		pre = stack[--top];
		pre->right = cur;
		pre->left = NULL;
		cur = pre;
	}
}




/********************************************************************************************************************
 * 思路二：按前序遍历方式进行第归
 * 	!key point-->第归函数中插入前节点指针地址，使其始终指向前一个节点，用于在第归中贯穿连接起前后；
 * 	通过传入的前节点地址指针，使其右指针指向本节点（前后连接），再使前节点指针指向自己，并向下第归
 * TC: O(n)   SC: O(n)
 * Runtime: 0 ms, faster than 100.00% if C online submissions
 * Memory Usage: 8.2 MB, less than 50.00% of C online submissions
 * ******************************************************************************************************************/

void Recursively_traversal(struct TreeNode *root, struct TreeNode **pre){
	if( root )
	{
		(*pre)->right = root;					//传入的前节点右指针指向本节点，使前后连接
		*pre = root; 						//本节点取代前节点，继续向下第归
		struct TreeNode *rchild = root->right;			//在下一步中，本节点右子树会被新节点取代，因此以rchild暂存
 		Recursively_traversal(root->left, pre); 		//按前序遍历先向左第归，此时下一步的前序节点是本节点，即pre；
		Recursively_traversal(rchild, pre);			//向右第归，注意此时的pre经过前一步中的第归后，已经变成上一步内最后一个非空root，而非上一步之前的本此循环中的root
		root->left = NULL;					//左指针置空
	}	
}

void flatten(struct TreeNode* root){
	struct TreeNode *pre;
	Recursively_traversal(root, &pre);
}




/********************************************************************************************************************
 * 思路三：迭代遍历，用栈保存每个节点的右子树；
 * 	   当某节点无左右子树（叶子）时，弹栈并使该节点的右指针指向出栈节点；
 * 	   当遇到叶子节点，且栈空时，完成全部连接
 * TC: O(n)   SC: O(n)
 * Runtime: 0 ms, faster than 100.00% of C online submissions
 * Memory Usage: 10 MB, less than 5.13% of C online submissions
 * ******************************************************************************************************************/

void flatten(struct TreeNode* root){
	struct TreeNode **stack = (struct TreeNode **) malloc(sizeof(struct TreeNode*));
	int stack_size = 1;
	int top = 0;
	while( root )
	{
		if( root->right )					//若右子树存在，则入栈
		{
			stack = (struct TreeNode **) realloc(stack, sizeof(struct TreeNode*) * (stack_size++));
			stack[top++] = root->right;
		}
		if( root->left )					//若左子树存在，则直接右接左
		{
			root->right = root->left;
		}
		else
		{
			if( 0 == top )	break;				//若左子树不存在：1、叶子节点，需要连当前节点右子树，需要弹栈
			root->right = stack[--top];			//       2、非叶子，不需要更改目前右连接，此时也可以弹栈后重新指向原来节点
		}
		root->left = NULL;
		root = root->right;
	}
}




/********************************************************************************************************************
 * 思路四：左边所有节点都应在右边节点之前，因此可迭代实现root->right接左，左接右
 * 		1.将树左子树接到右子树：
 * 			a.若左子树为空，不变；
 * 			b.若右子树为空，直接右接左；
 * 			c.若左右皆不为空，找到左子树的最右叶节点，使其右指针指向此时树根的右子树
 * 			d.左右子树都为空的情况，即找到了最右叶子节点 or 只有root一个节点（直接作为while条件）
 *		2.此时树根左子树置空
 *		3.树根右子树变成下一个树根，重新开始右接左，直到树根为NULL
 * TC: O(n)   SC: O(1)
 * Runtime: 4 ms, faster than 97.58% of C online submissions
 * Memory Usage: 7.9 MB, less than 100.00% of C online submissions 
 * ******************************************************************************************************************/

void flatten(struct TreeNode* root){
	while( root && (root->left || root->right) )				//若root无左右子树，即传入root仅一个节点,直接结束循环
	{
		if( root->left )						//若无左子树，不进行任何操作
		{
			if( !root->right )					//若无右子树，直接将右接左
			{
				root->right = root->left;		
			}
			else 							//若左右均存在
			{
				struct TreeNode *cur = root->left;			
				while( cur->right )				//找到当前root左子树的最右叶子节点
				{
					cur = cur->right;
				}		
				cur->right = root->right;			//先将找到的最大叶子连接到当前root右子树，不丢失root->right
				root->right = root->left;			//再右接左
			}
			root->left = NULL;
		}
		root = root->right;
	}
}




/********************************************************************************************************************
 * 参考Discussion中高票解法：@dhruv2 < https://leetcode.com/problems/flatten-binary-tree-to-linked-list/discuss/37243/My-accepted-solution-in-C >
 * 思路五：第归先暂时完成右子树的连接，
 * 	   再检查是否存在左子树：若存在，替换右子树为左节点，并将左节点最右叶子连接至当前节点
 * 	   			 若不存在，当前右子树即为正确连接
 * TC: O(n)   SC: O(n)
 * Runtime: 12 ms, faster than 22.09% of C online submissions
 * Memory Usage: 8.2 MB, less than 63.25% of C online submissions
 * ******************************************************************************************************************/

struct TreeNode *Recursively_traversal(struct TreeNode *root)
{
	if( root )
	{
		if( root->right )
		{
			root->right = Recursively_traversal(root->right);		//先向右第归后暂时完成连接
		}
		if( root->left )							//若无左子树，当前连接正确；若有，则向下执行
		{
			struct TreeNode *p1 = root->right;				//修改前先暂存临时右子树
			root->right = Recursively_traversal(root->left);		//正确连接当前节点右子树为左节点
			struct TreeNode *p2 = root->right;				
			while( p2->right )						//找到左节点的最右叶子节点
			{
				p2 = p2->right;
			}
			p2->right = p1;							//最右叶子节点连接之前的临时右子树
			root->left = NULL;
		}
	}
	return root;
}

void flatten(struct TreeNode* root){
	Recursively_traversal(root);
}
